#include <god.hpp>

#define MALE 0
#define FEMALE 1

God::God()
{
    db = DatabaseManager();
}

God::~God()
{
}

void God::catastrophe()
{
    db.clearDatabase();
    animals.clear();
}

void God::spawnAnimal(const Animal& current_animal)
{
    // Add to memory
    animals[current_animal.name] = current_animal;

    std::vector<std::vector<stat_type>> tmp;
    tmp.emplace_back(std::vector<stat_type>{
            stat_type(current_animal.name),
            stat_type(current_animal.kind),
            stat_type(current_animal.chromosome),
            stat_type(current_animal.generation),
            stat_type(current_animal.immunity),
            stat_type(current_animal.gender),
            stat_type(current_animal.age),
            stat_type(current_animal.height),
            stat_type(current_animal.weight),
            stat_type(current_animal.static_fitness)
    });

    // Add to database
    db.insertRows(tmp);
}

void God::killAnimals(const std::vector<std::string> &names)
{
    // Remove from database
    db.deleteRows(names);

    // Remove from memory
    for (const auto &lamb_to_slaughter : names)
        animals.erase(lamb_to_slaughter);
}

void God::mate(const std::string &name1, const std::string &name2)
{
    // Animal objects of 2 parents
    const auto& parent1 = animals[name1];
    const auto& parent2 = animals[name2];

    // Generate chromosomes of the child
    auto child_chromosome = helper::get_random_mixture(parent1.chromosome, parent2.chromosome);

    // Mutate chromosomes
    for(auto& bit : child_chromosome)
        if(helper::weighted_prob(parent1.mutation_probability))
            bit = (bit == '1')?'0':'1';

    // Spawn child (if probable)
    if(helper::weighted_prob(parent1.conceiving_probability))
    {
        spawnAnimal(Animal(parent1.kind,
                       child_chromosome,
                       std::max(parent1.generation, parent2.generation) + 1,
                       "",
                       {(parent1.X + parent2.X) / 2,
                       (parent1.Y + parent2.Y) / 2}));
    }
}

void God::happyNewYear()
{
    // Vector for [ (Animal, death_factor) ]
    std::vector<std::pair<Animal, double>> animals_vec;

    for(auto& animal : animals)
    {
        animal.second.generate_death_factor();
        animals_vec.push_back({animal.second, 0.0});
    }

    // Sort animal_vec by death factor

    std::sort(std::execution::par,
        animals_vec.begin(),
        animals_vec.end(),
        [](const std::pair<Animal, double>& x, const std::pair<Animal, double>& y){
            return x.first.death_factor > y.first.death_factor;
    });

    // std::cout << "Ages after sorting: ";
    // for(const auto& i : animals_vec)
    // {
    //     std::cout << i.first.age << ' ';
    // }
    // std::cout << '\n';

    // Mark the animals in animal_vec for death

    std::for_each(std::execution::par, animals_vec.begin(), animals_vec.end(), [&animals_vec](std::pair<Animal, double>& x){
        x.second = helper::weighted_prob(std::exp(-x.first.get_fitness() / (animals_vec.size() / 10.0)));
        //x.second = helper::weighted_prob(pow(x.first.get_fitness() / animals_vec.size(), 1 / 1.75));
    });

    // Remove the above marked animals from the f****** universe

    std::vector<std::string> animals_to_be_slaughtered;

    for(const auto& animal_tuple : animals_vec)
    {
        if(animal_tuple.second == 1)
        {
            // Being dragged to the slaughterhouse
            animals_to_be_slaughtered.push_back(animal_tuple.first.name);
        }
    }

    animals_vec.clear(); animals_vec.shrink_to_fit();

    killAnimals(animals_to_be_slaughtered);

    std::cout << "Animals slaughtered = " << animals_to_be_slaughtered.size() << '\n';

    // Yearly mating season begins

    int newborns = 0;

    std::unordered_map<std::string, std::vector<Animal>> animalsByKind;
    for(const auto& animal : animals)
        animalsByKind[animal.second.kind].push_back(animal.second);

    int index_parent1, index_parent2;
    for(auto& animal_tuple : animalsByKind)
    {
        auto& animal_list = animal_tuple.second;
        std::vector<Animal> males, females;
        for(const auto& animal : animal_list)
            if(animal.gender == MALE)
            {
                if(animal.age >= animal.mating_age_start && animal.age <= animal.mating_age_end)
                {
                    males.push_back(animal);
                }
            }
            else
            {
                if(animal.age >= animal.mating_age_start && animal.age <= animal.mating_age_end)
                {
                    females.push_back(animal);
                }
            }

        std::mt19937_64 rng; rng.seed(std::random_device()());

        while(males.size() > 0 && females.size() > 0)
        {
            std::uniform_int_distribution<int> dis(0, std::min(females.size(), males.size()) - 1);
            index_parent1 = dis(rng);
            index_parent2 = dis(rng);
            const auto& parent1 = males[index_parent1];
            const auto& parent2 = females[index_parent2];
            mate(parent1.name, parent2.name);

            males.erase(males.begin() + index_parent1);
            females.erase(females.begin() + index_parent2);
            males.shrink_to_fit();
            females.shrink_to_fit();
            newborns++;
        }
    }

    std::cout << "Newborns : " << newborns << '\n';
    std::cout << "Current population : " << animals.size() << '\n';

    // Yearly age incrementing todo: parallel v sequential performance test

    std::for_each(std::execution::par, animals.begin(), animals.end(), [](auto& x){
        x.second.increment_age();
    });
}

std::vector<Animal> God::animalSort(bool (*comp)(const Animal &, const Animal &))
{
    std::vector<Animal> animal_vec;
    for (auto &i : animals)
    {
        animal_vec.push_back(i.second);
    }
    animal_vec.shrink_to_fit();
    std::sort(animal_vec.begin(), animal_vec.end(), comp);
    return animal_vec;
}

std::unordered_map<std::string, std::vector<Animal>> God::animalSortByKind(bool (*comp)(const Animal &, const Animal &))
{
    std::unordered_map<std::string, std::vector<Animal>> animal_map;
    for (const auto &i : animals)
    {
        animal_map[i.second.kind].push_back(i.second);
    }
    for (auto &i : animal_map)
    {
        std::sort(i.second.begin(), i.second.end(), comp);
    }
    return animal_map;
}
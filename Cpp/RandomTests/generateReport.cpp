#include <god.hpp>
#include <iostream>
#include <memory>
#include <prakhar1989/ProgressBar.hpp>
#include <stat_fetcher.hpp>

void evaluation(const God &god)
{
    std::cout << "Population: " << stat_fetcher::getPopulation(god.organisms) << '\n';
    std::cout << "Deaths: " << god.recent_deaths << '\n';
    std::cout << "Births: " << god.recent_births << '\n';

    std::cout << "Average height: " << stat_fetcher::getStatAverage(god.organisms, "height") << '\n';
    std::cout << "Average weight: " << stat_fetcher::getStatAverage(god.organisms, "weight") << '\n';

    double low, high;
    std::string attribute;

    attribute = "age";
    std::tie(low, high) = stat_fetcher::getStatGap(god.organisms, attribute);
    std::cout << attribute << " - Lowest: " << low << " | Highest: " << high << '\n';

    attribute = "generation";
    std::tie(low, high) = stat_fetcher::getStatGap(god.organisms, "generation");
    std::cout << attribute << " - Lowest: " << low << " | Highest: " << high << '\n';

    std::cout << "Kind Distribution:\n";
    for (const auto &kind : stat_fetcher::getKindDistribution(god.organisms))
    {
        std::cout << kind.first << " : " << kind.second << '\n';
    }

    std::cout << "\n\n";
}

int main()
{
    unsigned int initial_organism_count = 200;
    unsigned int years_to_simulate = 100;

    God allah;
    allah.reset_species("deer");

    ProgressBar progressBar(years_to_simulate, 70, '#', '-');

    while (initial_organism_count--)
    {
        allah.spawnOrganism(std::make_shared<Animal>("deer", 10, true));
    }

    std::cout << "\n\nINITIAL EVALUATION:\n\n";
    evaluation(allah);

    std::cout << "Simulating " << years_to_simulate << " years\n";
    unsigned int i = 0;
    while (i++ < years_to_simulate)
    {
        allah.happyNewYear();

        //allah.sendDataToPy();

        ++progressBar;
        if (i % 10 == 0)
            progressBar.display();

        // evaluation(allah);


        if (allah.organisms.size() == 0)
        {
            std::cout << "Population extinct at year #" << i << "\n";
            break;
        }
        if (allah.organisms.size() >= 35000)
        {
            std::cout << "Overpopulated at year #" << i << "\n";
            break;
        }
    }

    std::cout << "\n\nFINAL EVALUATION:\n\n";
    evaluation(allah);
}

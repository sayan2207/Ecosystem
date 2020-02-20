#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include <fstream>
#include <helper.hpp>
#include <math.h>
#include <climits>
#include <iostream>
#include <variant>
#include <EcosystemTypes.hpp>

class Animal
{
public:
    std::string name;
    std::string kind;
    chromosome_map_type chromosome_structure;

    // Fixed for a species

    double mutation_probability;
    double conceiving_probability;
    unsigned int mating_age_start;
    unsigned int mating_age_end;
    unsigned int max_age;
    unsigned int chromosome_number;
    double age_on_death;
    double fitness_on_death;
    double age_fitness_on_death_ratio;
    double height_on_vitality;
    double weight_on_vitality;
    double height_on_stamina;
    double weight_on_stamina;
    double height_on_speed;
    double weight_on_speed;
    double vitality_on_appetite;
    double stamina_on_appetite;
    double vitality_on_speed;
    double stamina_on_speed;
    double sleep_restore_factor;
    double theoretical_maximum_base_vitality;
    double theoretical_maximum_vitality_multiplier;
    double theoretical_maximum_base_stamina;
    double theoretical_maximum_stamina_multiplier;
    double theoretical_maximum_height;
    double theoretical_maximum_weight;
    double theoretical_maximum_base_height;
    double theoretical_maximum_base_weight;
    double theoretical_maximum_height_multiplier;
    double theoretical_maximum_weight_multiplier;
    double theoretical_maximum_speed;
    double theoretical_maximum_base_speed;
    double theoretical_maximum_speed_multiplier;
    double theoretical_maximum_base_appetite;

    // Fixed for the organism throughout their lifetime

    std::string chromosome;
    unsigned int generation;
    double immunity;
    unsigned int gender;    // 0 - male, 1 - female

    // Changes slowly - once every year (during mating season)

    double death_factor;
    unsigned int age;
    double max_vitality_at_age;
    double max_stamina_at_age;
    double max_speed_at_age;
    double max_appetite_at_age;
    double height;
    double weight;
    double vision_radius; // Todo

    // Changes dynamically every moment

    double vitality;
    double stamina;
    double speed;
    double appetite;
    unsigned int X;
    unsigned int Y;
    bool asleep;

    double static_fitness;
    double dynamic_fitness;

    Animal() = default;
    Animal(const std::string& kind, const std::string& chromosome = "", const unsigned int& generation = 1, const std::string& name = "", const std::pair<unsigned int, unsigned int>& XY = helper::random_location());
    double get_base_vitality();
    double get_base_stamina();
    double get_vitality_multiplier();
    double get_stamina_multiplier();
    double get_max_height();
    double get_base_height();
    double get_height_multiplier();
    double get_max_weight();
    double get_base_weight();
    double get_weight_multiplier();
    double get_immunity();
    double get_base_speed();
    double get_speed_multiplier();
    double get_base_appetite();
    unsigned int get_gender();
    void evaluate_static_fitness();
    void evaluate_dynamic_fitness();
    void increment_age();
    void increment_vitality_by(const double&);
    void decrement_vitality_by(const double&);
    void increment_stamina_by(const double&);
    void decrement_stamina_by(const double&);
    void sleep(const double&);
    void eat(const double&);
    double get_die_of_age_factor();
    double get_die_of_fitness_factor();
    void generate_death_factor();
    double get_fitness() const;

    std::map<std::string, stat_type> get_stats();
};


#endif // ANIMAL_HPP

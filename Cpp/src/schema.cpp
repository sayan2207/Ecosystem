#include <schema.hpp>

namespace schema
{
    extern const std::vector<std::pair<std::string, SQLType>> schemaMaster{
        {"name", SQLType::TEXT},
        {"kind", SQLType::TEXT},
        {"chromosome", SQLType::TEXT},
        {"generation", SQLType::INT},
        {"immunity", SQLType::FLOAT},
        {"gender", SQLType::INT},
        {"age", SQLType::INT},
        {"height", SQLType::FLOAT},
        {"weight", SQLType::FLOAT},
        {"static_fitness", SQLType::FLOAT}};

    extern const std::vector<std::pair<std::string, SQLType>> schemaAnimal{
        {"year", SQLType::INT},
        {"male_population", SQLType::FLOAT},
        {"female_population", SQLType::FLOAT},
        {"matable_male_population", SQLType::FLOAT},
        {"matable_female_population", SQLType::FLOAT},
        {"conceiving_probability", SQLType::FLOAT},
        {"mating_age_start", SQLType::FLOAT},
        {"mating_age_end", SQLType::FLOAT},
        {"max_age", SQLType::FLOAT},
        {"mutation_probability", SQLType::FLOAT},
        {"offsprings_factor", SQLType::FLOAT},
        {"age_on_death", SQLType::FLOAT},
        {"fitness_on_death", SQLType::FLOAT},
        {"age_fitness_on_death_ratio", SQLType::FLOAT},
        {"height_on_speed", SQLType::FLOAT},
        {"height_on_stamina", SQLType::FLOAT},
        {"height_on_vitality", SQLType::FLOAT},
        {"weight_on_speed", SQLType::FLOAT},
        {"weight_on_stamina", SQLType::FLOAT},
        {"weight_on_vitality", SQLType::FLOAT},
        {"vitality_on_appetite", SQLType::FLOAT},
        {"vitality_on_speed", SQLType::FLOAT},
        {"stamina_on_appetite", SQLType::FLOAT},
        {"stamina_on_speed", SQLType::FLOAT},
        {"theoretical_maximum_base_appetite", SQLType::FLOAT},
        {"theoretical_maximum_base_height", SQLType::FLOAT},
        {"theoretical_maximum_base_speed", SQLType::FLOAT},
        {"theoretical_maximum_base_stamina", SQLType::FLOAT},
        {"theoretical_maximum_base_vitality", SQLType::FLOAT},
        {"theoretical_maximum_base_weight", SQLType::FLOAT},
        {"theoretical_maximum_height", SQLType::FLOAT},
        {"theoretical_maximum_speed", SQLType::FLOAT},
        {"theoretical_maximum_weight", SQLType::FLOAT},
        {"theoretical_maximum_height_multiplier", SQLType::FLOAT},
        {"theoretical_maximum_speed_multiplier", SQLType::FLOAT},
        {"theoretical_maximum_stamina_multiplier", SQLType::FLOAT},
        {"theoretical_maximum_vitality_multiplier", SQLType::FLOAT},
        {"theoretical_maximum_weight_multiplier", SQLType::FLOAT},
        {"sleep_restore_factor", SQLType::FLOAT},
        {"average_generation", SQLType::FLOAT},
        {"average_immunity", SQLType::FLOAT},
        {"average_age", SQLType::FLOAT},
        {"average_height", SQLType::FLOAT},
        {"average_weight", SQLType::FLOAT},
        {"average_max_appetite_at_age", SQLType::FLOAT},
        {"average_max_speed_at_age", SQLType::FLOAT},
        {"average_max_stamina_at_age", SQLType::FLOAT},
        {"average_max_vitality_at_age", SQLType::FLOAT},
        {"average_static_fitness", SQLType::FLOAT},
        {"average_dynamic_fitness", SQLType::FLOAT},
        {"average_vision_radius", SQLType::FLOAT}};

    extern const std::vector<std::pair<std::string, SQLType>> schemaPlant{
        {"year", SQLType::INT},
        {"population", SQLType::FLOAT},
        {"matable_population", SQLType::FLOAT},
        {"conceiving_probability", SQLType::FLOAT},
        {"mating_age_start", SQLType::FLOAT},
        {"mating_age_end", SQLType::FLOAT},
        {"max_age", SQLType::FLOAT},
        {"mutation_probability", SQLType::FLOAT},
        {"offsprings_factor", SQLType::FLOAT},
        {"age_on_death", SQLType::FLOAT},
        {"fitness_on_death", SQLType::FLOAT},
        {"age_fitness_on_death_ratio", SQLType::FLOAT},
        {"height_on_vitality", SQLType::FLOAT},
        {"weight_on_vitality", SQLType::FLOAT},
        {"theoretical_maximum_base_height", SQLType::FLOAT},
        {"theoretical_maximum_base_vitality", SQLType::FLOAT},
        {"theoretical_maximum_base_weight", SQLType::FLOAT},
        {"theoretical_maximum_height", SQLType::FLOAT},
        {"theoretical_maximum_weight", SQLType::FLOAT},
        {"theoretical_maximum_height_multiplier", SQLType::FLOAT},
        {"theoretical_maximum_vitality_multiplier", SQLType::FLOAT},
        {"theoretical_maximum_weight_multiplier", SQLType::FLOAT},
        {"average_generation", SQLType::FLOAT},
        {"average_immunity", SQLType::FLOAT},
        {"average_age", SQLType::FLOAT},
        {"average_height", SQLType::FLOAT},
        {"average_weight", SQLType::FLOAT},
        {"average_max_vitality_at_age", SQLType::FLOAT},
        {"average_static_fitness", SQLType::FLOAT},
        {"average_dynamic_fitness", SQLType::FLOAT}};

}; // namespace schema





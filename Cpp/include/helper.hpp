#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <utility>
#include <random>
#include <vector>

namespace helper
{
    extern unsigned int map_height;
    extern unsigned int map_width;
    extern std::string to_binary(const unsigned int&);
    extern unsigned int to_decimal(const std::string&);
    extern std::string random_binary(const unsigned int&);
    extern std::string random_name(const int&);
    extern std::pair<unsigned int, unsigned int> random_location();
    extern double get_value_from_chromosome(const std::string&, const unsigned int&, const unsigned int&, const double& offset);
    extern double weighted_average(const std::vector<double>& values, const std::vector<double>& weights);
};

#endif // HELPER_HPP

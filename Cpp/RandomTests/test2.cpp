#include <god.hpp>
#include <iostream>
#include <helper.hpp>

int main()
{
    Animal obj("deer");
    map_maker maker;
    auto ans = maker.var_map_banana(obj);
    std::cout << ans.size() << '\n';
    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        auto [key, inner_map] = *it;
        std::cout << "\n\n*************** Property *************\n" << key << "\n";
        for(const auto& [name, data] : inner_map)
            std::cout << name << ": " << data.getString() << "index: " << data.getIndex() << '\n';

        // *static_cast<int*>(data.address)
    }
}

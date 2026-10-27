#include <iostream>
#include"includes/forward_list.hpp"
#include"includes/poolallocate.hpp"
#include"includes/random.hpp"
#include"includes/random_list.hpp"
#include<map>
#include<random>
#include<format>
#include<print>
#include <fmt/core.h> 
#include <fmt/format.h>


int main(int, char**){
    std::map<int,int> test_map;
    random_map(test_map,10);
    for (const auto& [key,value] : test_map)
    {
       fmt::print("{} {}\n", key, value);
    }
    fmt::print("___________________________\n");
    using MapPoolAlloc = poolallocate<std::pair<const int, int>, 10>;
    std::map<int, int, std::less<int>, MapPoolAlloc> map2;
    random_map(map2,10);
    for (const auto& [key,value] : map2)
    {
       fmt::print("{} {}\n", key, value);
    }
    forward_list<int> test_list;
    random_list(test_list,10);
    for (auto i = test_list.begin(); i!=test_list.end(); ++i)
    {
        fmt::print("{} ", *i);
    }
    std::cout << "\n";

    fmt::print("_______________________________________\n");

    using ListPoolAlloc = poolallocate<int, 10>;
    forward_list<int, ListPoolAlloc>list2;

    random_list(list2,10);
    for (auto i = list2.begin(); i!=list2.end(); ++i)
    {
        fmt::print("{} ", *i);
    }
    std::cout << "\n";
    
    std::cout << __cplusplus << "\n";

}

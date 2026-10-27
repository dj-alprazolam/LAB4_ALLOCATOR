#include <iostream>
#include"includes/forward_list.hpp"
#include"includes/poolallocate.hpp"
#include"includes/random.hpp"
#include"includes/random_list.hpp"
#include<map>
#include<random>


int main(int, char**){
    std::map<int,int> test_map;
    random_map(test_map,10);
    using MapPoolAlloc = poolallocate<std::pair<const int, int>, 10>;
    std::map<int, int, std::less<int>, MapPoolAlloc> map2;
    random_map(map2,10);
    for (const auto& pair : map2)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    forward_list<int> test_list;
    random_list(test_list,10);

    using ListPoolAlloc = poolallocate<int, 10>;
    forward_list<int, ListPoolAlloc>list2;

    random_list(list2,10);
    for (auto i = list2.begin(); i!=list2.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    

}

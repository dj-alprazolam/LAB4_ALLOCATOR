#pragma once
#include <random>

template <typename T>
void random_list(T &list, size_t n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valDist(1, 1000);

    for (size_t i = 0; i < n; ++i)
    {
        list.push_back(valDist(gen));
    }
}
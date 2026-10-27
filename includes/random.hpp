#pragma once
#include <random>
#include <map>

template <typename T>
void random_map(T &m, size_t n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valDist(1, 1000);

    for (size_t i = 0; i < n; ++i)
    {
        m.emplace(i, valDist(gen));
    }
}
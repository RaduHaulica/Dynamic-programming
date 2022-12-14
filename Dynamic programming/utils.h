#pragma once

template<int n>
int minCost(int i, int j, std::array<std::array<int, n>, n>& costs, std::array<std::array<int, n>, n>& valueCache, int& callCounter)
{
    callCounter++;
    if (j < 0 || j >= n)
        return INT_MAX;
    if (valueCache[i][j] != -1)
    {
        return valueCache[i][j];
    }
    if (i == 0)
        return costs[i][j];
    int value = costs[i][j] + std::min(minCost<n>(i - 1, j - 1, costs, valueCache, callCounter), std::min(minCost<n>(i - 1, j, costs, valueCache, callCounter), minCost<n>(i - 1, j + 1, costs, valueCache, callCounter)));
    valueCache[i][j] = value;
    return value;
}

template<int n>
void printArray(std::array<std::array<int, n>, n> numbers)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << std::format("{0:3} ", numbers[i][j]);
        std::cout << '\n';
    }
}

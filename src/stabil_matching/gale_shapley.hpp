#ifndef GALE_SHAPLEY_HPP
#define GALE_SHAPLEY_HPP

#include <vector>
#include <map>
#include <string>

namespace StabilMatching
{
    std::map<int, int> solveGaleShapley(
        int n,
        std::vector<std::vector<int>> &prefA,
        std::vector<std::vector<int>> &prefB);
}

#endif
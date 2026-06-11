
#ifndef PRIMS_HPP
#define PRIMS_HPP

#include <vector>
namespace Greedy
{
    struct PrimsEdge
    {
        int u, v, weight;
    };

    struct PrimsResult
    {
        std::vector<PrimsEdge> mstEdges;
        int totalWeight;
    };

    PrimsResult solvePrims(int n, const std::vector<std::vector<PrimsEdge>> &adj);
}

#endif
#ifndef KRUSKALS_HPP
#define KRUSKALS_HPP

#include <vector>

namespace Greedy
{
    struct KruskalEdge
    {
        int u, v, weight;
    };

    struct KruskalsResult
    {
        std::vector<KruskalEdge> mstEdges;
        int totalWeight;
    };

    KruskalsResult solveKruskals(int n, const std::vector<KruskalEdge> &edges);

}

#endif
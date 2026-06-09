#ifndef DIJKSTRAS_HPP
#define DIJKSTRAS_HPP

#include <vector>
#include <utility>

namespace Greedy
{
    typedef std::pair<int, int> DijkstraEdge;

    struct DijkstraResult
    {
        std::vector<int> distances;
        std::vector<int> predecessors;
    };

    DijkstraResult solveDijkstra(int startNode, const std::vector<std::vector<DijkstraEdge>> &adj);
}
#endif

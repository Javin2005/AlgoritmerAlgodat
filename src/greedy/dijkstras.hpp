#ifndef DIJKSTRAS_HPP
#define DIJKSTRAS_HPP

#include <vector>
#include <utility>

namespace Greedy
{
    typedef std::pair<int, int> Edge;

    struct DijkstraResult
    {
        std::vector<int> distances;
        std::vector<int> predecessors;
    };

    DijkstraResult solveDijkstra(int startNode, const std::vector<std::vector<Edge>> &adj);
}
#endif

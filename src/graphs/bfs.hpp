#ifndef BFS_HPP
#define BFS_HPP

#include <vector>
namespace Graphs
{
    struct BFSResult
    {
        std::vector<int> traversalOrder;
        std::vector<int> distances;
    };

    BFSResult solveBFS(int startNode, const std::vector<std::vector<int>> &adj);

}
#endif
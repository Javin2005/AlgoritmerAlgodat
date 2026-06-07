#include "bfs.hpp"
#include <queue>

using namespace std;

namespace Graphs
{
    BFSResult solveBFS(int startNode, const vector<vector<int>> &adj)
    {
        int n = adj.size();
        BFSResult result;
        result.distances.assign(n, -1);

        vector<bool> visited(n, false);
        queue<int> q;

        visited[startNode] = true;
        result.distances[startNode] = 0;
        q.push(startNode);

        while (!q.empty())
        {

            int u = q.front();
            q.pop();

            result.traversalOrder.push_back(u);

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    result.distances[v] = result.distances[u] + 1;
                    q.push(v);
                }
            }
        }
        return result;
    }
}

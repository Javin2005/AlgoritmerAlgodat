#include "dijkstras.hpp"

#include <queue>
#include <limits>

using namespace std;

namespace Greedy
{
    DijkstraResult solveDijkstra(int startNode, const vector<vector<Edge>> &adj)
    {
        int n = adj.size();
        DijkstraResult result;

        const int INF = numeric_limits<int>::max();
        result.distances.assign(n, INF);
        result.predecessors.assign(n, -1);

        result.distances[startNode] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, startNode});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > result.distances[u])
                continue;

            for (auto &edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;

                if (result.distances[u] + weight < result.distances[v])
                {
                    result.distances[v] = result.distances[u] + weight;
                    result.predecessors[v] = u;
                    pq.push({result.distances[v], v});
                }
            }
        }

        return result;
    }
}
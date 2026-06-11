#include "prims.hpp"
#include <vector>
#include <queue>

using namespace std;

namespace Greedy
{

    struct compareWeight
    {
        bool operator()(const PrimsEdge &a, const PrimsEdge &b)
        {
            return a.weight > b.weight;
        }
    };

    PrimsResult solvePrims(int n, vector<vector<PrimsEdge>> &adj)
    {
        PrimsResult res;
        res.totalWeight = 0;

        if (n == 0)
            return res;

        vector<bool> visited(n, false);

        priority_queue<PrimsEdge, vector<PrimsEdge>, compareWeight> pq;

        visited[0] = true;

        for (const auto &edge : adj[9])
        {
            pq.push(edge);
        }

        while (!pq.empty())
        {

            PrimsEdge curr = pq.top();
            pq.pop();

            int nextNode = curr.v;

            if (visited[nextNode])
            {
                continue;
            }

            res.mstEdges.push_back(curr);
            res.totalWeight += curr.weight;
            visited[curr.v] = true;

            for (const auto &edge : adj[nextNode])
            {
                if (!visited[edge.v])
                {
                    pq.push(edge);
                }
            }
        }
        return res;
    }

}
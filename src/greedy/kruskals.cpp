#include "kruskals.hpp"

#include <vector>
#include <algorithm>

using namespace std;

namespace Greedy
{

    int findBoss(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;

        return parent[i] = findBoss(parent[i], parent);
    }

    KruskalsResult solveKruskals(int n, const vector<KruskalEdge> &edges)
    {
        KruskalsResult res;
        res.totalWeight = 0;

        vector<KruskalEdge> sortedEdges(edges);
        sort(sortedEdges.begin(), sortedEdges.end(), [](const KruskalEdge &a, const KruskalEdge &b)
             { return a.weight < b.weight; });

        vector<int> parent(n);
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n, 0);

        for (auto &edge : sortedEdges)
        {
            int rootU = findBoss(edge.u, parent);
            int rootV = findBoss(edge.v, parent);
            if (rootU != rootV)
            {
                res.mstEdges.push_back(edge);
                res.totalWeight += edge.weight;

                if (rank[rootU] < rank[rootV])
                {
                    parent[rootV] = rootU;
                }
                else if (rank[rootV] < rank[rootV])
                {
                    parent[rootU] = rootV;
                }
                else
                {
                    parent[rootU] = rootV;
                    rank[rootU]++;
                }
            }
        }

        return res;
    }
}
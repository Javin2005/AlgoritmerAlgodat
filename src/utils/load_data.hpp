#ifndef LOAD_DATA_HPP
#define LOAD_DATA_HPP

#include <vector>
#include <string>
#include <iostream>
#include "../stabil_matching/gale_shapley.hpp"
#include "../graphs/bfs.hpp"
#include "../graphs/dfs.hpp"
#include "../greedy/interval_scheduling.hpp"
#include "../greedy/dijkstras.hpp"
#include "../greedy/kruskals.hpp"
#include "generate_data.hpp"
#include <fstream>

using namespace std;

bool loadEdgeListData(string filename, int &n, vector<Greedy::KruskalEdge> &edges)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file: " << filename << endl;
        return false;
    }
    file >> n;
    edges.clear();

    int u, numNeighbors;

    while (file >> u >> numNeighbors)
    {
        for (int i = 0; i < numNeighbors; i++)
        {
            int v, weight;
            file >> v >> weight;

            if (u < v)
            {
                edges.push_back({u, v, weight});
            }
        }
    }
    file.close();
    return true;
}

bool loadWeightedGraphData(string filename, int &n, vector<vector<Greedy::DijkstraEdge>> &adj)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file: " << filename << endl;
        return false;
    }
    file >> n;
    adj.assign(n, vector<Greedy::DijkstraEdge>());

    for (int i = 0; i < n; i++)
    {
        int nodeID, numNeighbor;
        file >> nodeID >> numNeighbor;
        for (int j = 0; j < numNeighbor; j++)
        {
            int neighbor, weight;
            file >> neighbor >> weight;
            adj[nodeID].push_back({neighbor, weight});
        }
    }

    file.close();
    return true;
}

bool loadIntervalData(string filename, int &n, vector<Greedy::Interval> &intervals)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file: " << filename << endl;
        return false;
    }
    file >> n;
    intervals.clear();
    for (int i = 0; i < n; i++)
    {
        int s, e;
        file >> s >> e;
        intervals.push_back({s, e, i});
    }
    file.close();
    return true;
}

bool loadGaleShapleyData(string filename, int &n, vector<vector<int>> &prefA,
                         vector<vector<int>> &prefB)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file: " << filename << endl;
        return false;
    }

    file >> n;

    prefA.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> prefA[i][j];
        }
    }

    prefB.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> prefB[i][j];
        }
    }

    file.close();
    return true;
}

bool loadGraphData(string filename, int &n, vector<vector<int>> &adj)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open the file: " << filename << endl;
        return false;
    }
    file >> n;
    adj.assign(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        int nodeID, numNeighbors;
        file >> nodeID >> numNeighbors;
        for (int j = 0; j < numNeighbors; j++)
        {
            int neighbor;
            file >> neighbor;
            adj[nodeID].push_back(neighbor);
        }
    }
    file.close();
    return true;
}

#endif
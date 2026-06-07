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
#include "generate_data.hpp"
#include <fstream>

using namespace std;

bool loadWeightedGraphData(string filename, int &n, vector<vector<Greedy::Edge>> &adj)
{
    ifstream file(filename);
    if (!file.is_open())
        return false;

    file >> n;
    adj.assign(n, vector<Greedy::Edge>());

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
        return false;

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
        cerr << "Kunde inte öppna filen: " << filename << endl;
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
        return false;

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
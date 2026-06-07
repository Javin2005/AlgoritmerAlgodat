#include <iostream>
#include <fstream>

#include "stabil_matching/gale_shapley.hpp"

#include "graphs/bfs.hpp"
#include "graphs/dfs.hpp"

#include "greedy/interval_scheduling.hpp"
#include "greedy/dijkstras.hpp"

#include "utils/load_data.hpp"
#include "utils/generate_data.hpp"

#include <chrono>
#include <limits>

using namespace std;

int main()
{
    cout << "1. Gale-Shapley" << endl;
    cout << "2. BFS (Breadth-First Search)" << endl;
    cout << "3. DFS (Depth-First Search)" << endl;
    cout << "4. Interval scheduling" << endl;
    cout << "5. Dijkstras" << endl;
    cout << "Välj algoritm:" << endl;

    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        string path = "../data/stabil_matching/large_test.txt";

        cout << "Hur många element: ";
        int element;
        cin >> element;

        generateLargeGaleShapley(element, path);

        int n;
        vector<vector<int>> prefA, prefB;

        if (loadGaleShapleyData(path, n, prefA, prefB))
        {
            auto start = chrono::high_resolution_clock::now();

            auto matches = StabilMatching::solveGaleShapley(n, prefA, prefB);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, milli> duration = end - start;

            cout << "Stabila matchingar hittade för n=" << n << ":" << endl;
            cout << "Tid det tog: " << duration.count() << " ms" << endl;
            int count = 0;
            for (auto const &[b, a] : matches)
            {
                if (count < 5)
                    cout << "Person B" << b << " matches med Person A" << a << endl;
                count++;
            }
            cout << "... och " << n - 5 << " till." << endl;
        }
    }

    if (choice == 2)
    {
        cout << "Hur många noder ska grafen ha: ";
        int n_nodes;
        cin >> n_nodes;

        string path = "../data/graphs/large_bfs_test.txt";
        generateRandomGraph(n_nodes, 2, path);

        int n;
        vector<vector<int>> adj;
        if (loadGraphData(path, n, adj))
        {
            cout << "Graf inläst! Redo att köra BFS." << endl;
            auto start = chrono::high_resolution_clock::now();

            auto res = Graphs::solveBFS(0, adj);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "BFS klar på " << duration.count() << " ms" << endl;
            cout << "Besöksordning (första 10): ";
            for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
            {
                cout << res.traversalOrder[i] << " ";
            }
            cout << endl;
        }
    }

    if (choice == 3)
    {
        cout << "Hur många noder ska grafen ha: ";
        int n_nodes;
        cin >> n_nodes;

        string path = "../data/graphs/large_bfs_test.txt";
        generateRandomGraph(n_nodes, 2, path);

        int n;
        vector<vector<int>> adj;
        if (loadGraphData(path, n, adj))
        {
            cout << "Graf inläst! Redo att köra DFS." << endl;

            auto start = chrono::high_resolution_clock::now();

            auto res = Graphs::solveDFS(0, adj);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "DFS klar på " << duration.count() << " ms" << endl;
            cout << "Besöksordning (första 10): ";
            for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
            {
                cout << res.traversalOrder[i] << " ";
            }
            cout << endl;
        }
    }

    if (choice == 4)
    {
        cout << "Hur många intervall ska genereras: ";
        int n_intervals;
        cin >> n_intervals;

        string path = "../data/greedy/large_intervals_test.txt";
        generateIntervalData(n_intervals, 1000000, path);

        int n;
        vector<Greedy::Interval> intervals;
        if (loadIntervalData(path, n, intervals))
        {
            cout << "Intervall inlästa! Kör greedy Scheduling..." << endl;

            auto start = chrono::high_resolution_clock::now();

            auto res = Greedy::solveIntervalScheduling(intervals);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "Algoritm klar! Lyckades schemalägga " << res.size() << " av " << n << " intervall." << endl;
            cout << "Tid: " << duration.count() << " ms" << endl;

            cout << "De första valda intervallen:" << endl;
            for (int i = 0; i < min((int)res.size(), 5); i++)
            {
                cout << "  Intervall [" << res[i].start << " -> " << res[i].end << "]" << endl;
            }
        }
    }

    if (choice == 5)
    {
        cout << "Hur många noder i den viktade grafen: ";
        int n_nodes;
        cin >> n_nodes;

        string path = "../data/greedy/large_dijkstra_test.txt";
        generateWeightedGraph(n_nodes, 3, path);

        int n;
        vector<vector<Greedy::Edge>> adj;
        if (loadWeightedGraphData(path, n, adj))
        {
            cout << "Viktad graf inläst! Kör dijkstras..." << endl;

            auto start = chrono::high_resolution_clock::now();

            auto res = Greedy::solveDijkstra(0, adj);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "Dijkstra klar på " << duration.count() << " ms" << endl;
            cout << "Kortaste avstånd från nod 0 till de första 10 noderna:" << endl;
            for (int i = 0; i < min(n, 10); i++)
            {
                cout << " Nod " << i << ": " << (res.distances[i] == numeric_limits<int>::max() ? -1 : res.distances[i]) << endl;
            }
        }
    }
    return 0;
}
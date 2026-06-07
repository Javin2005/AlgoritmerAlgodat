#include <iostream>
#include "stabil_matching/gale_shapley.hpp"
#include "utils/generate_data.hpp"
#include <chrono>

#include <fstream>
using namespace std;

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

int main()
{
    std::cout << "Välj algoritm:" << std::endl;
    std::cout << "1. Gale-Shapley" << std::endl;

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

    return 0;
}
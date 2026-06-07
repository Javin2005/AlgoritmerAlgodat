#ifndef GENERATE_DATA_HPP
#define GENERATE_DATA_HPP

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

void generateLargeGaleShapley(int n, string filename)
{
    ofstream file(filename);
    file << n << endl;

    vector<int> prefs(n);
    iota(prefs.begin(), prefs.end(), 0);

    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < n; i++)
    {
        shuffle(prefs.begin(), prefs.end(), g);
        for (int val : prefs)
        {
            file << val << " ";
        }
        file << endl;
    }

    for (int i = 0; i < n; i++)
    {
        shuffle(prefs.begin(), prefs.end(), g);
        for (int val : prefs)
        {
            file << val << " ";
        }
        file << endl;
    }

    file.close();
    cout << "Filen " << filename << " med n=" << n << " har skapats!" << endl;
}
#endif
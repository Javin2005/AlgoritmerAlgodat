#include "gale_shapley.hpp"
#include <vector>
#include <queue>
#include <map>

using namespace std;

namespace StabilMatching
{
    map<int, int> solveGaleShapley(int n, vector<vector<int>> &prefA,
                                   vector<vector<int>> &prefB)
    {

        vector<int> matchB(n, -1);

        queue<int> freeAs;
        for (int i = 0; i < n; i++)
        {
            freeAs.push(i);
        }

        vector<int> nextProposal(n, 0);

        vector<vector<int>> rankB(n, vector<int>(n));
        for (int b = 0; b < n; b++)
        {
            for (int rank = 0; rank < n; rank++)
            {
                int a = prefB[b][rank];
                rankB[b][a] = rank;
            }
        }

        while (!freeAs.empty())
        {
            int a = freeAs.front();

            int b = prefA[a][nextProposal[a]];
            nextProposal[a]++;

            if (matchB[b] == -1)
            {
                matchB[b] = a;
                freeAs.pop();
            }
            else
            {
                int currentA = matchB[b];

                if (rankB[b][a] < rankB[b][currentA])
                {
                    matchB[b] = a;
                    freeAs.pop();
                    freeAs.push(currentA);
                }
            }
        }
        map<int, int> finalMatches;
        for (int b = 0; b < n; b++)
        {
            finalMatches[b] = matchB[b];
        }

        return finalMatches;
    }
}

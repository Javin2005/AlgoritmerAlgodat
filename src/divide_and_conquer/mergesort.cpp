#include "mergesort.hpp"

#include <vector>

using namespace std;

namespace DivideAndConquer
{

    vector<int> merge(const vector<int> &left, const vector<int> &right)
    {
        vector<int> res;
        res.reserve(left.size() + right.size());

        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size())
        {
            if (left[i] <= right[j])
            {
                res.push_back(left[i]);
                i++;
            }
            else
            {
                res.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size())
        {
            res.push_back(left[i]);
            i++;
        }
        while (j < right.size())
        {
            res.push_back(right[j]);
            j++;
        }
        return res;
    }

    vector<int> mergeSort(vector<int> &list, int &count)
    {
        if (list.size() <= 1)
            return list;

        count++;
        int mid = list.size() / 2;

        vector<int> left(list.begin(), list.begin() + mid);
        vector<int> right(list.begin() + mid, list.end());

        left = mergeSort(left, count);
        right = mergeSort(right, count);

        return merge(left, right);
    }

    mergeSortResult solveMergeSort(const vector<int> &unSortedList)
    {
        vector<int> unS(unSortedList);
        mergeSortResult res;
        res.amountOfDivides = 0;

        res.SortedList = mergeSort(unS, res.amountOfDivides);
        return res;
    }
}
#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>

namespace DivideAndConquer
{

    struct mergeSortResult
    {
        std::vector<int> SortedList;
        int amountOfDivides;
    };

    mergeSortResult solveMergeSort(const std::vector<int> &unSortedList);

}

#endif
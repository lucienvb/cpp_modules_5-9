#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    ~PmergeMe();

    template <typename T>
    void mergeInsertSort(std::vector<T>& arr, int left, int right);

    // template <typename T>
    // void insertionSort(std::vector<T>& arr, int left, int right);

    // template <typename T>
    // void merge(std::vector<T>& arr, int left, int mid, int right);

};

#endif

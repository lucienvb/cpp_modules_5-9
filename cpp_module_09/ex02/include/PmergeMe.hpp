#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <string>
#include <exception>
#include <limits>
#include <chrono>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    ~PmergeMe();

    bool parse(char **argv);

    void printVec();
    size_t getVecSize();

    void mergeInsertSort();
    void mergeInsertSort(std::vector<int>& arr, int left, int right);
    void insertionSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);

private:
    std::vector<int> _vec;
    std::list<int> _list;
};

#endif

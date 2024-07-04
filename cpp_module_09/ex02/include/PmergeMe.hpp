#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <exception>
#include <limits>
#include <chrono>
#include <array>

#define MINIMUM_NUMBERS 3000

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    ~PmergeMe();

    bool parse(char **argv);

    void setSize(int argc);

    void printVec();
    void printArr();

    size_t getVecSize();
    size_t getArrSize();

    void mergeInsertSortVec();
    void mergeInsertSortVec(std::vector<int>& arr, int left, int right);
    void insertionSortVec(std::vector<int>& arr, int left, int right);
    void mergeVec(std::vector<int>& arr, int left, int mid, int right);

    void mergeInsertSortArr();
    template <size_t N>
    void mergeInsertSortArr(std::array<int, N>& arr, int left, int right);
    template <size_t N>
    void insertionSortArr(std::array<int, N>& arr, int left, int right);
    template <size_t N>
    void mergeArr(std::array<int, N>& arr, int left, int mid, int right);

private:
    std::vector<int> _vec;
    std::array<int, MINIMUM_NUMBERS> _arr;
    size_t _size;
};

#endif

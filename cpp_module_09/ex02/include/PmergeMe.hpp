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
    void printList();
    size_t getVecSize();
    size_t getListSize();

    void mergeInsertSortVec();
    void mergeInsertSortVec(std::vector<int>& arr, int left, int right);
    void insertionSortVec(std::vector<int>& arr, int left, int right);
    void mergeVec(std::vector<int>& arr, int left, int mid, int right);

    void mergeList(typename std::list<int>::iterator left, typename std::list<int>::iterator mid, typename std::list<int>::iterator right);
    void insertionSortList(typename std::list<int>::iterator left, typename std::list<int>::iterator right);
    void mergeInsertSortList(std::list<int>& lst, typename std::list<int>::iterator left, typename std::list<int>::iterator right, int size);
    void mergeInsertSortList();

private:
    std::vector<int> _vec;
    std::list<int> _list;
};

#endif

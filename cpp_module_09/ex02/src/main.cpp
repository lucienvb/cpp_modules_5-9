#include "PmergeMe.hpp"

std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Error: no arguments provided" << std::endl;
        return 1;
    }
    PmergeMe sort;
    if (!sort.parse(argv)) {
        std::cout << "Error: invalid arguments" << std::endl;
        return 1;
    }

    std::cout << "Before:\t";
    sort.printVec();
    // sort.printList();
    auto start = std::chrono::high_resolution_clock::now();
    sort.mergeInsertSortVec();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationVec = end - start;

    start = std::chrono::high_resolution_clock::now();
    sort.mergeInsertSortList();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationList = end - start;

    std::cout << "After:\t";
    // sort.printVec();
    sort.printList();
    std::cout << "Time to process a range of " << sort.getVecSize() << " elements with std::vector : " << durationVec.count() * 1000 << " ms" << std::endl;
    std::cout << "Time to process a range of " << sort.getListSize() << " elements with std::list : " << durationList.count() * 1000 << " ms" << std::endl;
    return 0;
}
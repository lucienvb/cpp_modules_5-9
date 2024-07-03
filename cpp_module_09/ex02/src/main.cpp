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

    std::cout << "Vector before:\t";
    sort.printVec();
    auto start = std::chrono::high_resolution_clock::now();
    sort.mergeInsertSort();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Vector after:\t";
    sort.printVec();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time to process a range of " << sort.getVecSize() << " elements with std::vector : " << duration.count() * 1000 << " ms" << std::endl;
    return 0;
}
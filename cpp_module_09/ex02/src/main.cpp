#include "PmergeMe.hpp"

int main() {
    PmergeMe merge;
    std::vector<int> arr = {34, 7, 23, 32, 5, 62, 32, 5, 62, 32, 5, 62, 1, 12, 2, 3, 56, 23, 54};

    merge.mergeInsertSort(arr, 0, arr.size() - 1);
    return 0;
}

// Test the merge-insert sort implementation
// int main() {

//     std::cout << "Original array: ";
//     for (const auto& num : arr) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//    mergeInsertSort(arr, 0, arr.size() - 1);

//     std::cout << "Sorted array: ";
//     for (const auto& num : arr) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
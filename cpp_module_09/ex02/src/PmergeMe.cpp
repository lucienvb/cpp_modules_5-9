#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj){
	if (this != &obj){
		*this = obj;
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj){
	if (this != &obj){
		// this->_max_size = obj._max_size;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

// // Function to merge two sorted ranges
// template <typename T>
// void	PmergeMe::merge(std::vector<T>& arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     std::vector<T> leftArr(n1);
//     std::vector<T> rightArr(n2);

//     std::copy(arr.begin() + left, arr.begin() + mid + 1, leftArr.begin());
//     std::copy(arr.begin() + mid + 1, arr.begin() + right + 1, rightArr.begin());

//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (leftArr[i] <= rightArr[j]) {
//             arr[k++] = leftArr[i++];
//         } else {
//             arr[k++] = rightArr[j++];
//         }
//     }

//     while (i < n1) {
//         arr[k++] = leftArr[i++];
//     }

//     while (j < n2) {
//         arr[k++] = rightArr[j++];
//     }
// }

// // Function to perform insertion sort on a range
// template <typename T>
// void	PmergeMe::insertionSort(std::vector<T>& arr, int left, int right) {
//     for (int i = left + 1; i <= right; ++i) {
//         T key = arr[i];
//         int j = i - 1;
//         while (j >= left && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             --j;
//         }
//         arr[j + 1] = key;
//     }
// }

// Merge-insert sort function
template <typename T>
void	PmergeMe::mergeInsertSort(std::vector<T>& arr, int left, int right) {
    (void)arr;
    (void)left;
    (void)right;
	std::cout << "test" << std::endl;
	
	// if (right - left + 1 <= 16) {
    //     insertionSort(arr, left, right);
    // } else {
    //     int mid = left + (right - left) / 2;
    //     mergeInsertSort(arr, left, mid);
    //     mergeInsertSort(arr, mid + 1, right);
    //     merge(arr, left, mid, right);
    // }
}

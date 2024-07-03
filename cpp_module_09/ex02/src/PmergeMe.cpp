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

bool PmergeMe::parse(char **argv) {
    try {
        for (int i = 1; argv[i]; i++) {
            if (argv[i][0] == '-')
                return false;
            long long num = std::stoi(argv[i]);
            if (num < 0 || num > std::numeric_limits<int>::max())
                return false;
            _vec.push_back(num);
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return true;
}

// // Function to merge two sorted ranges
// template <typename T>
void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    std::copy(arr.begin() + left, arr.begin() + mid + 1, leftArr.begin());
    std::copy(arr.begin() + mid + 1, arr.begin() + right + 1, rightArr.begin());

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

// // Function to perform insertion sort on a range
void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge-insert sort function
void PmergeMe::mergeInsertSort(std::vector<int>& arr, int left, int right) {
    // (void)arr;
    // (void)left;
    // (void)right;
	// std::cout << "test" << std::endl;
	
	if (right - left + 1 <= 16) {
        insertionSort(arr, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeInsertSort(arr, left, mid);
        mergeInsertSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void PmergeMe::mergeInsertSort() {
    mergeInsertSort(_vec, 0, _vec.size() -1);
}

size_t PmergeMe::getVecSize() {
    return _vec.size();
}

void PmergeMe::printVec() {
    for (const int& i : _vec)
        std::cout << i << " ";
    std::cout << "\n";
}

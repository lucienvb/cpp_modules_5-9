#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	if (this != &obj){
		*this = obj;
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj) {
	if (this != &obj){
		this->_vec = obj._vec;
		this->_arr = obj._arr;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parse(char **argv) {
    try {
        int j = 0;
        for (int i = 1; argv[i]; i++) {
            if (argv[i][0] == '-')
                return false;
            long long num = std::stoi(argv[i]);
            if (num < 0 || num > std::numeric_limits<int>::max())
                return false;
            _vec.push_back(num);
            _arr[j++] = num;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return true;
}

void PmergeMe::setSize(int argc) {
    _size = argc - 2;
}

void PmergeMe::mergeVec(std::vector<int>& arr, int left, int mid, int right) {
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

void PmergeMe::insertionSortVec(std::vector<int>& arr, int left, int right) {
    for (int i = left; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortVec(std::vector<int>& arr, int left, int right) {
	
	if (right - left < THRESHOLD) {
        insertionSortVec(arr, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeInsertSortVec(arr, left, mid);
        mergeInsertSortVec(arr, mid + 1, right);
        mergeVec(arr, left, mid, right);
    }
}

void PmergeMe::mergeInsertSortVec() {
    mergeInsertSortVec(_vec, 0, _vec.size() -1);
}

template <size_t N>
void PmergeMe::mergeArr(std::array<int, N>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::array<int, MINIMUM_NUMBERS> leftArr;
    std::array<int, MINIMUM_NUMBERS> rightArr;
    
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

template <size_t N>
void PmergeMe::insertionSortArr(std::array<int, N>& arr, int left, int right) {
    
    for (int i = left; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <size_t N>
void PmergeMe::mergeInsertSortArr(std::array<int, N>& arr, int left, int right) {
	
	if (right - left < THRESHOLD) {
        insertionSortArr(arr, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeInsertSortArr(arr, left, mid);
        mergeInsertSortArr(arr, mid + 1, right);
        mergeArr(arr, left, mid, right);
    }
}

void PmergeMe::mergeInsertSortArr() {
    mergeInsertSortArr(_arr, 0, _size);
}

size_t PmergeMe::getVecSize() {
    return _vec.size();
}

size_t PmergeMe::getArrSize() {
    return _size + 1;
}

void PmergeMe::printVec() {
    for (const int& i : _vec)
        std::cout << i << " ";
    std::cout << "\n";
}

void PmergeMe::printArr() {
    for (size_t i = 0; i <= _size; i++)
        std::cout << _arr[i] << " ";
    std::cout << "\n";
}

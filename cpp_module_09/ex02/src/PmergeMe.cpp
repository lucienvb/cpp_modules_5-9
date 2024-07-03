#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj){
	if (this != &obj){
		*this = obj;
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj){
	if (this != &obj){
		this->_vec = obj._vec;
		this->_list = obj._list;
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
            _list.push_back(num);
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return true;
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

void PmergeMe::mergeInsertSortVec(std::vector<int>& arr, int left, int right) {
	
	if (right - left + 1 <= 16) {
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

static void mergeList(typename std::list<int>::iterator left, typename std::list<int>::iterator mid, typename std::list<int>::iterator right) {
    std::list<int> leftList(left, std::next(mid));
    std::list<int> rightList(std::next(mid), std::next(right));

    auto it1 = leftList.begin();
    auto it2 = rightList.begin();
    auto it = left;

    while (it1 != leftList.end() && it2 != rightList.end()) {
        if (*it1 <= *it2) {
            *it++ = *it1++;
        } else {
            *it++ = *it2++;
        }
    }

    while (it1 != leftList.end()) {
        *it++ = *it1++;
    }

    while (it2 != rightList.end()) {
        *it++ = *it2++;
    }
}

static void insertionSortList(typename std::list<int>::iterator left, typename std::list<int>::iterator right) {
    for (auto it = std::next(left); it != std::next(right); ++it) {
        auto key = *it;
        auto j = std::prev(it);
        while (std::distance(left, j) >= 0 && *j > key) {
            *std::next(j) = *j;
            if (j == left) break;
            --j;
        }
        *std::next(j) = key;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& lst, typename std::list<int>::iterator left, typename std::list<int>::iterator right, int size) {
    // (void)lst;
    if (size <= 16) {
        insertionSortList(left, right);
    } else {
        int midSize = size / 2;
        auto mid = std::next(left, midSize - 1);
        mergeInsertSortList(lst, left, mid, midSize);
        mergeInsertSortList(lst, std::next(mid), right, size - midSize);
        mergeList(left, mid, right);
        printList();
    }
}

void PmergeMe::mergeInsertSortList() {
    // mergeInsertSortList(_list, _list.begin(), std::prev(_list.end()), _list.size());
    mergeInsertSortList(_list, _list.begin(), std::prev(_list.end()), _list.size());
}

size_t PmergeMe::getVecSize() {
    return _vec.size();
}

size_t PmergeMe::getListSize() {
    return _list.size();
}

void PmergeMe::printVec() {
    for (const int& i : _vec)
        std::cout << i << " ";
    std::cout << "\n";
}

void PmergeMe::printList() {
    for (const int& i : _list)
        std::cout << i << " ";
    std::cout << "\n";
}

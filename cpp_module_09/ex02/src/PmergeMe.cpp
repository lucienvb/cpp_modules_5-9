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
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj){
	if (this != &obj){
		*this = obj;
	}
}

RPN& RPN::operator=(const RPN &obj){
	if (this != &obj){
		// this->_max_size = obj._max_size;
	}
	return (*this);
}

RPN::~RPN() {}
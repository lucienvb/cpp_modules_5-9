#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj){
	if (this != &obj){
		*this = obj;
	}
}

RPN& RPN::operator=(const RPN &obj){
	if (this != &obj){
		_stack = obj._stack;
	}
	return (*this);
}

RPN::~RPN() {}

void	RPN::parse(std::string str) {
	size_t i = 0;
	while (str[i]) {
		if (str[i] == ' ') {
			i++;
			continue;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			_stack.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' ||
				str[i] == '*' || str[i] == '/')
			_stack.push(str[i]);
		else {
			std::cout << "Error: invalid input" << std::endl;
			return ;
		}
		// std::cout << _stack << std::endl;
		i++;
	}
}
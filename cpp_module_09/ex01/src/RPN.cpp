#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj){
	if (this != &obj){
		*this = obj;
	}
}

RPN& RPN::operator=(const RPN &obj){
	if (this != &obj){
		_numbers = obj._numbers;
		_operations = obj._operations;
	}
	return (*this);
}

RPN::~RPN() {}

void	RPN::printNumbersTop() {
	std::cout << _numbers.top() << std::endl;
}

void	RPN::calculate(int first, int second, char operation) {
	int result;

	if (operation == '+')
		result = first + second;
	else if (operation == '-')
		result = first - second;
	else if (operation == '/')
		result = first / second;
	else
		result = first * second;
	_numbers.push(result);
}

bool	RPN::process() {
	char	operation;
	int 	second;
	int 	first;

	while (_numbers.size() > 1 && _operations.size() > 0) {
		first = _numbers.top();
		_numbers.pop();
		second = _numbers.top();
		_numbers.pop();
		operation = _operations.top();
		_operations.pop();
		calculate(first, second, operation);
	}
	return true;
}

bool	RPN::parse(std::string str) {
	int i = str.size() - 1;

	while (i >= 0) {
		if (str[i] == ' ') {
			i--;
			continue;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			_numbers.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' ||
				str[i] == '*' || str[i] == '/')
			_operations.push(str[i]);
		else
			return false;
		i--;
	}
	if (_numbers.size() < 2 || _operations.size() < 1)
		return false;
	return true;
}
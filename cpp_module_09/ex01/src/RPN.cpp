#include "RPN.hpp"

RPN::RPN(): _current(-1) {}

RPN::RPN(const RPN &obj){
	if (this != &obj){
		*this = obj;
	}
}

RPN& RPN::operator=(const RPN &obj){
	if (this != &obj){
		_numbers = obj._numbers;
		_current = obj._current;
	}
	return (*this);
}

RPN::~RPN() {}

void	RPN::printResult() {
	std::cout << _current << std::endl;
}

void	RPN::calculate(char operation) {
	
	long long top = _numbers.top();
	_numbers.pop();

	if (operation == '+')
		_current += top;
	else if (operation == '-')
		_current -= top;
	else if (operation == '/')
		_current /= top;
	else
		_current *= top;
}

bool	RPN::isDecimal(char num) {
	return (num >= '0' && num <= '9');
}

bool	RPN::isOperation(char operation) {
	return (operation == '+' || operation == '-' ||
				operation == '*' || operation == '/');
}

bool	RPN::processRPN(std::string str) {
	int i = 0;

	while (str[i]) {

		if (str[i] == ' ') {
			i++;
			continue;
		}
		else if (isDecimal(str[i])) {
			if (_current == -1)
				_current = str[i] - '0';
			else
				_numbers.push(str[i] - '0');
		}
		else if (isOperation(str[i]) && _numbers.size() > 0)
			calculate(str[i]);
		else
			return false;
		i++;
	}
	return true;
}
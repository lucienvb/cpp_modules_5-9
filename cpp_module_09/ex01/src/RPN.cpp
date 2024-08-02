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
	}
	return (*this);
}

RPN::~RPN() {}

void	RPN::printResult() {
	std::cout << _numbers.top() << std::endl;
}

bool	RPN::calculate(char operation) {
	
	long long head = _numbers.top();
	_numbers.pop();
	long long next = _numbers.top();
	_numbers.pop();
	long long new_head = 0;

	if (operation == '+')
		new_head = next + head;
	else if (operation == '-')
		new_head = next - head;
	else if (operation == '/') {
		if (head == 0)
			return false;
		new_head = next / head;
	}
	else
		new_head = next * head;
	_numbers.push(new_head);
	return true;
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
		else if (str[i+1] && str[i] == '-' && isDecimal(str[i+1])) {
			_numbers.push((str[i+1] - '0') * -1);
			i++;
		}
		else if (isDecimal(str[i])) {
			_numbers.push(str[i] - '0');
		}
		else if (isOperation(str[i]) && _numbers.size() > 1) {
			if (!calculate(str[i]))
				return false;
		}
		else
			return false;
		i++;
	}
	if (_numbers.size() > 1)
		return false;
	return true;
}
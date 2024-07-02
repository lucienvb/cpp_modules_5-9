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

void	RPN::printTop() {
	printVariant(_stack.top());
}

void RPN::printVariant(const VarType& var) {
    if (var.type == ValueType::INT) {
        std::cout << var.intValue << std::endl;
    } else if (var.type == ValueType::CHAR) {
        std::cout << var.charValue << std::endl;
    }
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
	_stack.push(result);
}

bool	RPN::process() {
	char	operation;
	VarType current = 0;
	int 	second;
	int 	first;

	while (_stack.size() > 2) {
		current = _stack.top();
		if (current.type == ValueType::INT) {
			first = current.intValue;
			_stack.pop();
		}
		else
			return false;
		current = _stack.top();
		if (current.type == ValueType::INT) {
			second = current.intValue;
			_stack.pop();
		}
		else
			return false;
		current = _stack.top();
		if (current.type == ValueType::CHAR) {
			operation = current.charValue;
			_stack.pop();
			calculate(first, second, operation);
		}
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
			_stack.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' ||
				str[i] == '*' || str[i] == '/')
			_stack.push(str[i]);
		else {
			std::cout << "Error: invalid input" << std::endl;
			return false;
		}
		i--;
	}
	return true;
}
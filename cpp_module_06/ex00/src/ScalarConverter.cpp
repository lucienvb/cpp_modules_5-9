#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Constructor ScalarConverter called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    std::cout << "Copy constructor ScalarConverter called" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    std::cout << "Assignment operator ScalarConverter called" << std::endl;
    (void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor ScalarConverter called" << std::endl;
}

void ScalarConverter::convert(std::string str) {

    std::cout << "str: " << str << std::endl;

}
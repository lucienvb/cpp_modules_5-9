#include "ScalarConverter.hpp"
#include <typeinfo>
#include <regex>

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

bool	ScalarConverter::isInt(std::string str) {
	std::regex floatRegex("\\d+");
    return std::regex_match(str, floatRegex);
}

bool isFloat(const std::string& str) {
    std::regex floatRegex("^\\d*\\.\\d+f$");
    return std::regex_match(str, floatRegex);
}

bool isDouble(const std::string& str) {
    std::regex doubleRegex("^\\d*\\.\\d+$");
    return std::regex_match(str, doubleRegex);
}

ScalarType ScalarConverter::checkType(std::string str) {
    if (str == "-inff" || str == "+inff")
        return ScalarType::PSEUDO_FLOAT;
    else if (str == "-inf" || str == "+inf" || str == "nan")
        return ScalarType::PSEUDO_DOUBLE;
    else if (str.length() == 1 && !std::isdigit(str[0])) {
        return ScalarType::CHAR;
	}
	if (str[0] == '-' || str[0] == '+') {
		str.erase(0, 1);
	}
    if (isInt(str))
	    return ScalarType::INT;
	else if (isFloat(str))
		return ScalarType::FLOAT;
	else if (isDouble(str))
		return ScalarType::DOUBLE;
	return ScalarType::UNKNOWN;
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printPseudoFloat(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float:  " << str << std::endl;
	std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
}

void ScalarConverter::printPseudoDouble(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float:  " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

// template <typename T> void	ScalarConverter::printChar(T c) {
// 	return static_cast<char>(c);
// }

void ScalarConverter::convert(std::string str) {

    std::cout << "str: " << str << std::endl;

	ScalarType type = checkType(str);

    std::cout << "Type: " << type << std::endl;

	switch (type) {
		case PSEUDO_FLOAT:
			printPseudoFloat(str);
		case PSEUDO_DOUBLE:
			printPseudoDouble(str);
		// case CHAR:
			// printChar(str[0]);



		default:
			printImpossible();
	}
	

    // int num = std::stoi(str);

    // int i = static_cast<int>(num);
    // std::cout << "i with " << typeid(i).name() << ": " << i << std::endl;

    // char c = static_cast<char>(num);
    // std::cout << "c with " << typeid(c).name() << ": " << c << std::endl;

    // float f = static_cast<float>(num);
    // std::cout << "f with " << typeid(f).name() << ": " << f << std::endl;
}

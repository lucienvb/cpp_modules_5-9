#include "ScalarConverter.hpp"
#include <typeinfo>
#include <regex>
#include <math.h>

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

template <typename T> void	ScalarConverter::printConversions(T conv) {
	std::cout << "char: ";
	printChar(conv);
	std::cout << "\nint: ";
	printInt(static_cast<int>(conv));
	std::cout << "\nfloat: ";
	printFloat(static_cast<float>(conv));
	std::cout << "\ndouble: ";
	printDouble(static_cast<double>(conv));
}

template <typename T> void	ScalarConverter::printChar(T c) {
	if (c <= 31 || c >= 127)
		std::cout << "Non displayable";
	else
		std::cout << static_cast<char>(c);
}

template <typename T> void	ScalarConverter::printInt(T i) {
	std::cout << i;
}

template <typename T> void	ScalarConverter::printFloat(T f) {
	std::cout << f;
	if (fmodf(f, 1.0f) == 0)
		std::cout << ".0";
	std::cout << "f";
}

template <typename T> void	ScalarConverter::printDouble(T d) {
	std::cout << d;
	if (fmod(d, 1.0) == 0)
		std::cout << ".0";
	std::cout << "\n";
}

void ScalarConverter::convert(std::string str) {

	ScalarType type = checkType(str);

	switch (type) {
		case PSEUDO_FLOAT:
			printPseudoFloat(str);
			return ;
		case PSEUDO_DOUBLE:
			printPseudoDouble(str);
			return ;
		case CHAR:
			printConversions(str[0]);
			return ;
		case INT:
			printConversions(std::stoi(str));
			return ;
		case FLOAT:
			printConversions(std::stof(str));
			return ;
		case DOUBLE:
			printConversions(std::stod(str));
			return ;
		case UNKNOWN:
			printImpossible();
	}
}

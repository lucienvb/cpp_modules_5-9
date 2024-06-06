#include "ScalarConverter.hpp"
#include <typeinfo>
#include <regex>
#include <math.h>
#include <limits.h>
#include <float.h>

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
	printInt(conv);
	std::cout << "\nfloat: ";
	printFloat(conv);
	std::cout << "\ndouble: ";
	printDouble(conv);
}

template <typename T> void	ScalarConverter::printChar(T c) {
	if (std::isnan(c) || c < CHAR_MIN || c > CHAR_MAX)
		std::cout << "impossible";
	else if (std::isprint(static_cast<char>(c)))
		std::cout << "\'" << static_cast<char>(c) << "\'";
	else
		std::cout << "Non displayable";
}

template <typename T> void	ScalarConverter::printInt(T i) {
	if (std::isnan(i) || 
		static_cast<int>(i) == INT32_MIN || 
		static_cast<int>(i) < INT32_MIN || 
		static_cast<int>(i) > INT32_MAX
		)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(i);
}

template <typename T> void	ScalarConverter::printFloat(T f) {
	if (std::isnan(f) || f < FLT_MIN || f > FLT_MAX)
		std::cout << "impossible";
	else {
		std::cout << static_cast<float>(f);
		if (static_cast<float>(f) - static_cast<int>(f) == 0)
			std::cout << ".0";
		std::cout << "f";
	}
}

template <typename T> void	ScalarConverter::printDouble(T d) {
	if (std::isnan(d) || d < DBL_MIN || d > DBL_MAX)
		std::cout << "impossible";
	else {
		std::cout << static_cast<double>(d);
		if (static_cast<double>(d) - static_cast<int>(d) == 0)
			std::cout << ".0";
		std::cout << "\n";
	}
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
			try {
				printConversions(std::stoi(str));
			}
			catch (std::exception &e) {
				std::cout << "exeption throwed: " << e.what() << std::endl;
			}
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

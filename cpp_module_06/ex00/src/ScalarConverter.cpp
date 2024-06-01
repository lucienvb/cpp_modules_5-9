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
	std::cout << c;
}

template <typename T> void	ScalarConverter::printInt(T i) {
	std::cout << i;
}

template <typename T> void	ScalarConverter::printFloat(T f) {
	std::cout << f;
}

template <typename T> void	ScalarConverter::printDouble(T d) {
	std::cout << d << "\n" << std::endl;
}

void ScalarConverter::convert(std::string str) {

	ScalarType type = checkType(str);

	switch (type) {
		case PSEUDO_FLOAT:
			printPseudoFloat(str);
		case PSEUDO_DOUBLE:
			printPseudoDouble(str);
		case CHAR:
			printConversions(static_cast<char>(str[0]));
		case INT:
			printConversions(static_cast<int>(std::stoi(str)));
		case FLOAT:
			printConversions(static_cast<float>(std::stof(str)));
		case DOUBLE:
			printConversions(static_cast<double>(std::stod(str)));
		case UNKNOWN:
			printImpossible();
	}
	
}

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>

enum ScalarType { 
	PSEUDO_FLOAT, 
	PSEUDO_DOUBLE, 
	CHAR, 
	INT, 
	FLOAT, 
	DOUBLE, 
	UNKNOWN 
	};

class ScalarConverter {
public:
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter &other) = delete;
    ScalarConverter& operator=(const ScalarConverter &other) = delete;
    ~ScalarConverter() = delete;

    static void			convert(std::string str);
    static ScalarType	checkType(std::string str);
    static bool			isInt(std::string str);

	static void 	printImpossible();
	static void 	printPseudoFloat(std::string str);
	static void 	printPseudoDouble(std::string str);

	template <typename T> static void	printConversions(const T &c);
	
	template <typename T> static void	printChar(const T &c);
	template <typename T> static void	printInt(const T &i);
	template <typename T> static void	printFloat(const T &f);
	template <typename T> static void	printDouble(const T &d);

};

#endif
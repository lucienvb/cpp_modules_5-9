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
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static void			convert(std::string str);
    static ScalarType	checkType(std::string str);
    static bool			isInt(std::string str);

	static void 	printImpossible();
	static void 	printPseudoFloat(std::string str);
	static void 	printPseudoDouble(std::string str);

	template <typename T> static void	printConversions(T c);
	
	template <typename T> static void	printChar(T c);
	template <typename T> static void	printInt(T i);
	template <typename T> static void	printFloat(T f);
	template <typename T> static void	printDouble(T d);

};

#endif
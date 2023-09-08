#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& ref);
	ScalarConverter& operator=(const ScalarConverter& ref);
	~ScalarConverter();
	
	static void convertChar(const long double value, bool flag);
	static void convertInt(const long double value, bool flag);
	static void convertfloat(const long double value, bool flag);
	static void convertDouble(const long double value, bool flag);

	static void convert(const std::string str);
};

#endif


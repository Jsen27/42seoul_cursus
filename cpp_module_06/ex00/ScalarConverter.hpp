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
	
	static void convert(const std::string str);

	static void convertChar(const double value, bool flag);
	static void convertInt(const int value, bool flag);
	static void convertfloat(const float value, bool flag);
	static void convertDouble(const double value, bool flag);

};

#endif


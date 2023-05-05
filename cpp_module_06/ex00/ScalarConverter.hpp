#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>
#include <cmath> // floor
#include <cstdlib> // strtod
#include <locale> // isprint

class ScalarConverter
{
private:
	double value_;
	bool flag_;
public:
	ScalarConverter(const std::string str);
	ScalarConverter(const ScalarConverter& ref);
	ScalarConverter& operator=(const ScalarConverter& ref);
	~ScalarConverter();
};

#endif

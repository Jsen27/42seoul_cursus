#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string str)
{
	char *end;

	flag_ = true;
	value_ = std::strtod(str.c_str(), &end);
}

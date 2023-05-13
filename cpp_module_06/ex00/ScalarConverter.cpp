#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	*this = ref;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
	(void)ref;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convertChar(const long double value, bool flag)
{
    std::cout << "Char: ";
    if (flag == true && std::isprint(static_cast<int>(value)) && !std::isnan(value))
        std::cout << static_cast<char>(value) << std::endl;
    else if (flag == false || std::isnan(value))
        std::cout << "impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::convertInt(const long double value, bool flag)
{
	std::cout << "Int: ";
	if (value < std::numeric_limits<int>::lowest() || value > std::numeric_limits<int>::max()
		|| flag == false || std::isinf(value) || std::isnan(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::convertfloat(const long double value, bool flag)
{
	std::cout << "Float: ";
    if (value < std::numeric_limits<float>::lowest())
        std::cout << "-inff" << std::endl;
    else if (value > std::numeric_limits<float>::max())
        std::cout << "inff" << std::endl;
    else if (flag == false)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::convertDouble(const long double value, bool flag)
{
	std::cout << "Double: ";
    if (value < -std::numeric_limits<double>::max())
        std::cout << "-inf" << std::endl;
    else if (value > std::numeric_limits<double>::max())
        std::cout << "inf" << std::endl;
    else if (flag == false)
        std::cout << "impossible" << std::endl;
    else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(const std::string str)
{
	char *end = NULL;
	long double value = std::strtold(str.c_str(), &end);
	bool flag = (strlen(end) == 0 || (strlen(end) == 1 && end[0] == 'f' && str[str.length() - 1] == 'f'));

	convertChar(value, flag);
	convertInt(value, flag);
	convertfloat(value, flag);
	convertDouble(value, flag);
}

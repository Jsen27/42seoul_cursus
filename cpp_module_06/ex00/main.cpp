#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "Usage : ./convert [string]" << std::endl;
		return 1;
	}

	ScalarConverter::convert(static_cast<std::string>(argv[1]));

	return 0;
}

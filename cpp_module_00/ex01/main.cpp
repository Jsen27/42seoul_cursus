#include "utils.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string ft_getline()
{
	std::string input;

	std::getline(std::cin, input);
	if (std::cin.fail())
	{
		std::cout << "EOF or ERROR !" << std::endl;
		exit(1);
	}
	return input;
}

int main()
{
	PhoneBook mybook;
	std::string input;
	
	while (1){
		std::cout << GREEN "Press enter your command   (Hint : ADD, SEARCH, EXIT)" BLUE << std::endl;
		input = ft_getline();
		if (input == "ADD")
			mybook.Addarray();
		else if (input == "SEARCH")
			mybook.Search_contact();
		else if (input == "EXIT")
			break;
		else
			std::cout << RED << input << RED " is not command" NC << std::endl;
	}
	std::cout << NC;
	return 0;
}
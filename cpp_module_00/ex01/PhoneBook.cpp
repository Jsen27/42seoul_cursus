#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->idx = 0;
}

void PhoneBook::Addarray()
{
	if (this->idx == 8)
		this->idx = 0;
	array[this->idx].Addcontact();
	this->idx++;
}

std::string	PhoneBook::print_wide(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + '.');
	else
		return (std::string(10 - str.size(), ' ') + str);
}

void PhoneBook::print_all(int idx)
{
	std::cout << std::endl << YELLOW "first name : " << this->array[idx].output(0) << std::endl;
	std::cout << "last name : " << this->array[idx].output(1) << std::endl;
	std::cout << "nickname : " << this->array[idx].output(2) << std::endl;
	std::cout << "phone number : " << this->array[idx].output(3) << std::endl;
	std::cout << "darkest secret : " << this->array[idx].output(4) << std::endl << std::endl;
}

void PhoneBook::Search_contact()
{
	int idx = 0, input = 0;

	if (this->idx == 0)
		std::cout << RED "Your PhoneBook is empty" << std::endl;
	else{
		std::cout << YELLOW "     index|first name| last name|  nickname" << std::endl;
		while (idx < this->idx){
			std::cout << "         " << idx << '|';
			std::cout << this->print_wide(this->array[idx].output(1)) << '|';
			std::cout << this->print_wide(this->array[idx].output(2)) << '|';
			std::cout << this->print_wide(this->array[idx].output(3)) << std::endl;
			idx++;
		}
		while (1){
			std::cout << std::endl << GREEN "Please enter the number you want" BLUE << std::endl;
			std::cin >> input;
			if (input > this->idx - 1 || input < 0)
				std::cout << std::endl << RED "Wrong number" << std::endl;
			else
			{
				print_all(input);
				return ;
			}
		}		
	}	
}
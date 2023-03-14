#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->idx = 0;
	this->total = 0;
}

void PhoneBook::Addarray()
{
	if (this->idx == 8)
		this->idx = 0;
	if (this->total < 8)
		this->total++;
	array[this->idx].Addcontact();
	this->idx++;
}

void	PhoneBook::print_wide(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) + '.';
	else
		std::cout << std::setw(10) << str;
}

void PhoneBook::print_all(int idx)
{
	std::cout << std::endl << YELLOW "first name : " << this->array[idx].output(1) << std::endl;
	std::cout << "last name : " << this->array[idx].output(2) << std::endl;
	std::cout << "nickname : " << this->array[idx].output(3) << std::endl;
	std::cout << "phone number : " << this->array[idx].output(4) << std::endl;
	std::cout << "darkest secret : " << this->array[idx].output(5) << std::endl << std::endl;
}

void PhoneBook::Search_contact()
{
	int idx = 0;
	std::string input;

	if (this->idx == 0)
		std::cout << RED "Your PhoneBook is empty" << std::endl;
	else{
		std::cout << YELLOW "     index|first name| last name|  nickname" << std::endl;
		while (idx < this->total){
			std::cout << std::setw(10) << idx << '|';
			print_wide(this->array[idx].output(1)); std::cout << '|';
			print_wide(this->array[idx].output(2)); std::cout << '|';
			print_wide(this->array[idx].output(3)); std::cout << std::endl;
			idx++;
		}
		while (1){
			std::cout << std::endl << GREEN "Please enter the number you want" BLUE << std::endl;
			input = ft_getline();
			try
			{
				idx = std::stoi(input);
			}
			catch (const std::exception &e)
			{
				idx = -1;
			}
			if (idx >= 0 && idx < this->total)
			{
				print_all(idx);
				break;
			}
			else
				std::cout << std::endl << RED "Wrong number" << std::endl;

		}
	}	
}
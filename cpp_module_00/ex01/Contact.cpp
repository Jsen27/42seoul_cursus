#include "Contact.hpp"

void Contact::Addcontact()
{
	std::cout << GREEN "Please enter your first name" BLUE << std::endl;
	this->firstname = ft_getline();
	std::cout << GREEN "Please enter your last name" BLUE << std::endl;
	this->lastname = ft_getline();
	std::cout << GREEN "Please enter your nick name" BLUE << std::endl;
	this->nickname = ft_getline();
	std::cout << GREEN "Please enter your number" BLUE << std::endl;
	this->number = ft_getline();
	std::cout << GREEN "Please enter your darkest secret" BLUE << std::endl;
	this->secret = ft_getline();
	std::cout << YELLOW "Save contact success !" << std::endl;
}

std::string Contact::output(int flag)
{
	if (flag == 1)
		return (this->firstname);
	else if (flag == 2)
		return (this->lastname);
	else if (flag == 3)
		return (this->nickname);
	else if (flag == 4)
		return (this->number);
	else
		return (this->secret);
}

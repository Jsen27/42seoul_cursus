#include "Contact.hpp"

void Contact::Addcontact()
{
	std::cout << GREEN "Please enter your first name" BLUE << std::endl;
	std::cin >> this->firstname;
	std::cout << GREEN "Please enter your last name" BLUE << std::endl;
	std::cin >> this->lastname;
	std::cout << GREEN "Please enter your nick name" BLUE << std::endl;
	std::cin >> this->nickname;
	std::cout << GREEN "Please enter your number" BLUE << std::endl;
	std::cin >> this->number;
	std::cout << GREEN "Please enter your darkest secret" BLUE << std::endl;
	std::cin >> this->secret;
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

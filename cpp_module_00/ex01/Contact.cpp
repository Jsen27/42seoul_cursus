#include "Contact.hpp"

void Contact::Addcontact()
{
	std::cout << "Please Enter Your First Name" << std::endl;
	std::cin >> this->firstname;
	std::cout << "Please Enter Your Last Name" << std::endl;
	std::cin >> this->lastname;
	std::cout << "Please Enter Your Nick Name" << std::endl;
	std::cin >> this->nickname;
	std::cout << "Please Enter your Number" << std::endl;
	std::cin >> this->number;
	std::cout << "Save Contact Success !" << std::endl;
}
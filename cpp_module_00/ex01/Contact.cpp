#include "main.hpp"

void Contact::Addcontact()
{
	std::cout << "Please Press Your First Name" << std::endl;
	std::cin >> this->firstname;
	std::cout << "Please Press Your Last Name" << std::endl;
	std::cin >> this->lastname;
	std::cout << "Please Press Your Nick Name" << std::endl;
	std::cin >> this->nickname;
	std::cout << "Please Press your Number" << std::endl;
	std::cin >> this->number;
	std::cout << "Save Contact Success !" << std::endl;
}
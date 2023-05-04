#include "Intern.hpp"

const char * Intern::NotMatchType::what() const throw()
{
	return "not match type";
}

Intern::Intern()
{}

Intern::Intern(const Intern& ref)
{
	static_cast<void>(ref);
}

Intern& Intern::operator=(const Intern& ref)
{
	static_cast<void>(ref);
	return *this;
}

Intern::~Intern()
{}

AForm* Intern::makeForm(const std::string type, const std::string name)
{
	std::string matchType[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	
	for (int i = 0; i < 3; i++){
		if (matchType[i] == type){
			switch (i){
			case 0:
				return new PresidentialPardonForm(name);
				break;
			case 1:
				return new RobotomyRequestForm(name);
				break;
			case 2:
				return new ShrubberyCreationForm(name);
				break;
			}
		}
	}
	std::cerr << "makeForm failed because ";
	throw Intern::NotMatchType();
}

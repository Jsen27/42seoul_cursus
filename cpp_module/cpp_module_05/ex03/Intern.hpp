#ifndef INTERN_HPP_
#define INTERN_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern
{
public:
	Intern();
	Intern(const Intern& ref);
	Intern& operator=(const Intern& ref);
	~Intern();

	AForm* makeForm(const std::string type, const std::string);

	class NotMatchType : public std::exception
	{
		const char * what() const throw();
	};
};

#endif

#ifndef SHRUBBERY_CREATIONFORM_HPP_
#define SHRUBBERY_CREATIONFORM_HPP_

#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string name);
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

	virtual void execute(const Bureaucrat& ref) const;

};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& ref);

#endif

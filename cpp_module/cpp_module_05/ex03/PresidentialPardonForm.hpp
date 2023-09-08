#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string name);
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

	virtual void execute(const Bureaucrat& ref) const;

};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& ref);

#endif

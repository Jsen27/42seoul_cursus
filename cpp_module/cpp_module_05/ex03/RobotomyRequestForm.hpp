#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string name);
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

	virtual void execute(const Bureaucrat& ref) const;

};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& ref);

#endif

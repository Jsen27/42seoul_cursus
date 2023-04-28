#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

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

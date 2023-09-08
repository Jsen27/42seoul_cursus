#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{
	std::cout << "Default constructor for RobotomyRequestForm class has been called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
: AForm(name, 72, 45)
{
	std::cout << "constructor for RobotomyRequestForm class has been created with " << AForm::getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExecute())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is being destroyed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &ref)
		AForm::operator=(ref);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& ref) const
{
	if (ref.getGrade() > this->getGradeExecute())
	{
		std::cerr << ref.getName() << " couldn't execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		if (rand() % 2)
			std::cout << ref.getName() << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomization of " << ref.getName() << " has failed." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& ref)
{
	os << "Name: " << ref.getName() << ", ";
	os << "Signed: " << std::boolalpha << ref.getSign() << ", ";
	os << "Grade required to sign: " << ref.getGradeSign() << ", ";
    os << "Grade required to execute: " << ref.getGradeExecute();
	return os;
}

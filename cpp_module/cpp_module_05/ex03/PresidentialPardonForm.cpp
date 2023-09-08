#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
	std::cout << "Default constructor for PresidentialPardonForm class has been called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
: AForm(name, 25, 5)
{
	std::cout << "constructor for PresidentialPardonForm class has been created with " << AForm::getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExecute())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is being destroyed." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &ref)
		AForm::operator=(ref);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& ref) const
{
	if (ref.getGrade() > this->getGradeExecute())
	{
		std::cerr << ref.getName() << " couldn't execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}

	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& ref)
{
	os << "Name: " << ref.getName() << ", ";
	os << "Signed: " << std::boolalpha << ref.getSign() << ", ";
	os << "Grade required to sign: " << ref.getGradeSign() << ", ";
    os << "Grade required to execute: " << ref.getGradeExecute();
	return os;
}

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150)
{
	std::cout << "Default constructor for Bureaucrat class has been called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name_(name), grade_(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Default constructor for Bureaucrat class has been created with " << this->name_ << " and " << this->grade_ << " grade" << std::endl;	
}

const std::string Bureaucrat::getName() const
{
	return this->name_;
}

int Bureaucrat::getGrade() const
{
	return this->grade_;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Too high . . .";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Too low . . .";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name_ << " is being destroyed." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref)
{
	std::cout << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
	return os;
}

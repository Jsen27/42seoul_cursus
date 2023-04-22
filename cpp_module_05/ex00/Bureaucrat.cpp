#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150)
{
	std::cout << "Default constructor for Bureaucrat class has been called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name_(name), grade_(grade)
{
	std::cout << "constructor for Bureaucrat class has been created with " << this->name_ << " and " << this->grade_ << " grade" << std::endl;	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name_(ref.name_), grade_(ref.grade_)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &ref)
		this->grade_ = ref.grade_;
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return this->name_;
}

const int Bureaucrat::getGrade() const
{
	return this->grade_;
}

void Bureaucrat::increaseGrade()
{
	if (this->grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade_--;
	std::cout << "promote " << *this << std::endl;
}

void Bureaucrat::decreaseGrade()
{
	if (this->grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_++;
	std::cout << "demote" << *this << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "too high . . .";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "too low . . .";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name_ << " is being destroyed." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return os;
}

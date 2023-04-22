#include "Form.hpp"

Form::Form() : name_("default"), sign_(false), grade_sign_(150), grade_execute_(150)
{
	std::cout << "Default constructor for Form class has been called." << std::endl;
}

Form::Form(const std::string name, const int sign, const int execute) : name_(name), sign_(false), grade_sign_(sign), grade_execute_(execute)
{
	std::cout << "constructor for Form class has been created with " << this->name_ << std::endl;
	if (sign < 1 || execute < 1)
		throw Form::GradeTooHighException();
	else if (sign > 150 || execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& ref) : name_(ref.name_), sign_(ref.sign_), grade_sign_(ref.grade_sign_), grade_execute_(ref.grade_execute_)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << name_ << " is being destroyed." << std::endl;
}

Form &Form::operator=(const Form& ref)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &ref)
		this->sign_ = ref.sign_;
	return *this;
}

const std::string Form::getName() const
{
	return this->name_;
}

bool Form::getSign() const
{
	return this->sign_;
}

int Form::getGradeSign() const
{
	return this->grade_sign_;
}

int Form::getGradeExecute() const
{
	return this->grade_execute_;
}

void Form::beSigned(const Bureaucrat &ref)
{
	if (ref.getGrade() > this->getGradeSign())
	{
		std::cerr << ref.getName() << " couldn't sign " << this->getName() << " because ";
		throw Form::GradeTooLowException();
	}
	if (this->sign_ == false)
	{
		this->sign_ = true;
		std::cout << ref.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "too high . . .";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "too low . . .";
}

std::ostream &operator<<(std::ostream &os, const Form &ref)
{
	os << "Name: " << ref.getName() << ", ";
	os << "Signed: " << std::boolalpha << ref.getSign() << ", ";
	os << "Grade required to sign: " << ref.getGradeSign() << ", ";
    os << "Grade required to execute: " << ref.getGradeExecute();
	return os;
}

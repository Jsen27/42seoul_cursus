#include "AForm.hpp"

AForm::AForm() : name_("default"), sign_(false), grade_sign_(150), grade_execute_(150)
{
	std::cout << "Default constructor for AForm class has been called." << std::endl;
}

AForm::AForm(const std::string name, const int sign, const int execute) : name_(name), sign_(false), grade_sign_(sign), grade_execute_(execute)
{
	std::cout << "constructor for AForm class has been created with " << this->name_ << std::endl;
	if (sign < 1 || execute < 1)
		throw AForm::GradeTooHighException();
	else if (sign > 150 || execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& ref) : name_(ref.name_), sign_(ref.sign_), grade_sign_(ref.grade_sign_), grade_execute_(ref.grade_execute_)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm " << name_ << " is being destroyed." << std::endl;
}

AForm &AForm::operator=(const AForm& ref)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &ref)
		this->sign_ = ref.sign_;
	return *this;
}

const std::string AForm::getName() const
{
	return this->name_;
}

bool AForm::getSign() const
{
	return this->sign_;
}

int AForm::getGradeSign() const
{
	return this->grade_sign_;
}

int AForm::getGradeExecute() const
{
	return this->grade_execute_;
}

void AForm::beSigned(const Bureaucrat &ref)
{
	if (ref.getGrade() > this->getGradeSign())
	{
		std::cerr << ref.getName() << " couldn't sign " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
	if (this->sign_ == false)
	{
		this->sign_ = true;
		std::cout << ref.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "too high . . .";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "too low . . .";
}

std::ostream &operator<<(std::ostream &os, const AForm &ref)
{
	os << "Name: " << ref.getName() << ", ";
	os << "Signed: " << std::boolalpha << ref.getSign() << ", ";
	os << "Grade required to sign: " << ref.getGradeSign() << ", ";
    os << "Grade required to execute: " << ref.getGradeExecute();
	return os;
}

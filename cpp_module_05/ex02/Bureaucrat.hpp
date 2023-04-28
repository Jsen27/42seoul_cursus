#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string name_;
	int grade_;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat& ref);

	const std::string getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();

	void signForm(AForm &form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char * what() const throw();
	};
	
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref);

#endif

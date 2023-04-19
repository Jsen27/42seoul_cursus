#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>

class Bureaucrat
{
private:
	const std::string name_;
	int grade_;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat& ref);
	Bureaucrat &operator=(const Bureaucrat& ref);
	const std::string getName() const;
	int getGrade() const;
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
	~Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref);

#endif

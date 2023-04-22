#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name_;
	bool sign_;
	const int grade_sign_;
	const int grade_execute_;

public:
	Form();
	Form(const std::string name, const int sign, const int execute);
	Form(const Form& ref);
	~Form();

	Form& operator=(const Form& ref);

	const std::string getName() const;
	int getSign() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void beSigned(const Bureaucrat &ref);
	
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

std::ostream& operator<<(std::ostream& os, const Form& ref);

#endif

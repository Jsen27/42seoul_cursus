#ifndef AFORM_HPP_
#define AFORM_HPP_

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name_;
	bool sign_;
	const int grade_sign_;
	const int grade_execute_;

public:
	AForm();
	AForm(const std::string name, const int sign, const int execute);
	AForm(const AForm& ref);
	virtual ~AForm();

	AForm& operator=(const AForm& ref);

	const std::string getName() const;
	bool getSign() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void beSigned(const Bureaucrat &ref);

	virtual void execute(const Bureaucrat& ref) const = 0;
	
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

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif

#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& ref);
	Bureaucrat &operator=(const Bureaucrat& ref);
	void test();
	~Bureaucrat();
};


#endif

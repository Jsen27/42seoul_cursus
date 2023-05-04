#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "***********************Test 1***********************" << std::endl;
	{
		Bureaucrat king("king", 1);
		Bureaucrat worker("worker", 150);
		ShrubberyCreationForm form("SSSSSS");
		try
		{
			std::cout << king << std::endl;
			std::cout << form << std::endl;
			king.signForm(form);
			std::cout << form << std::endl;
			form.execute(king);
			form.execute(worker);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "***********************Test 2***********************" << std::endl;

	{
		Bureaucrat king("king", 1);
		Bureaucrat worker("worker", 150);
		RobotomyRequestForm form("RRRRRRRRRR");
		try
		{
			std::cout << king << std::endl;
			std::cout << form << std::endl;
			king.signForm(form);
			std::cout << form << std::endl;
			form.execute(king);
			form.execute(worker);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "***********************Test 3***********************" << std::endl;

	{
		Bureaucrat king("king", 1);
		Bureaucrat worker("worker", 150);
		PresidentialPardonForm form("PPPPPPP");
		try
		{
			std::cout << king << std::endl;
			std::cout << form << std::endl;
			king.signForm(form);
			std::cout << form << std::endl;
			form.execute(king);
			form.execute(worker);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

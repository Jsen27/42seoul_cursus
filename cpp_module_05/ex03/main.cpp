#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "***********************Test 1***********************" << std::endl;
	{
		Bureaucrat king("king", 1);
		Intern intern;
		AForm* newform;

		try
		{
			newform = intern.makeForm("ShrubberyCreation", "ABCD");
			newform->execute(king);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		delete newform;
	}

	std::cout << "***********************Test 2***********************" << std::endl;

	{
		Bureaucrat king("king", 1);
		Intern intern;
		AForm* failform;

		try
		{
			failform = intern.makeForm("failfailfailfail", "ABCD");
			failform->execute(king);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

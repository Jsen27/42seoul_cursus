#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		Bureaucrat king("king", 1);
		ShrubberyCreationForm paper("paper");
		
		try
		{
			std::cout << king << std::endl;
			std::cout << paper << std::endl;
			paper.execute(king);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	
	return 0;
}

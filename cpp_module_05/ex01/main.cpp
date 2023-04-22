#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat king("king", 1);
		Form paper("paper", 150, 150);

		std::cout << king << std::endl;
		std::cout << paper << std::endl;
		king.signForm(paper);
		std::cout << paper << std::endl;

	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat king("king", 1);
		Form paper("paper", 150, 150);

		std::cout << king << std::endl;
		std::cout << paper << std::endl;
		king.signForm(paper);
		std::cout << paper << std::endl;

	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}

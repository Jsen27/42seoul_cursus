#include "Bureaucrat.hpp"

int main()
{
	std::cout << "***********************Test 1***********************" << std::endl;
	{
		Bureaucrat king("king", 1);
		Form paper("paper", 150, 150);
		try
		{
			std::cout << king << std::endl;
			std::cout << paper << std::endl;
			king.signForm(paper);
			std::cout << paper << std::endl;

		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << "***********************Test 2***********************" << std::endl;

	{
		Bureaucrat worker("worker", 100);
		Form document("document", 50, 50);
		try
		{

			std::cout << worker << std::endl;
			std::cout << document << std::endl;
			worker.signForm(document);
			std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;

		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}	
	return 0;
}

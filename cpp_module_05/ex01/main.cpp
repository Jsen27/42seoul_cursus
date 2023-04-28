#include "Bureaucrat.hpp"

int main()
{
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
	
	{
		Bureaucrat worker("worker", 100);
		Form document("document", 50, 50);
		try
		{

			std::cout << worker << std::endl;
			std::cout << document << std::endl;
			worker.signForm(document);
			std::cout << document << std::endl;

		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}	
	return 0;
}

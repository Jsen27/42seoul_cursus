#include "Bureaucrat.hpp"

int main()
{
	std::cout << "***********************Test 1***********************" << std::endl;
	{
		try
		{
			Bureaucrat kim("KIM", 50);
			Bureaucrat errorman("ERRORMAN", 999);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "***********************Test 2***********************" << std::endl;

	{
		try
		{
			Bureaucrat high_man("high_man", 1);
			Bureaucrat low_man("low_man", 150);

			std::cout << high_man << std::endl << low_man << std::endl;
			low_man.increaseGrade();
			low_man.decreaseGrade();
			high_man.increaseGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

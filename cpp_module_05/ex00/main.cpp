#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat kim("KIM", 1);
		Bureaucrat high_man("ERRORman", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}

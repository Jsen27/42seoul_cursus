#include "Span.hpp"

int main()
{
	std::cout << "***********************Test 1***********************" << std::endl;
	try
	{
		Span spn(10);
		for(int i = 0; i < 5; i++){
			spn.addNumber(i + 1);
			spn.addNumber(i + 100);
		}
		std::cout << spn.shortestSpan() << std::endl;
		spn.addNumber(1);
		std::cout << "NO PRINT ! ! ! ! ! !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "***********************Test 2***********************" << std::endl;
	try
	{
		Span spn(5);
		spn.addNumber(1);
		spn.addNumber(50);
		spn.addNumber(9999);
		std::cout << spn.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "***********************Test 3***********************" << std::endl;
	try
	{
		Span spn(20000);
		for (int i = 0; i < 20000; i++)
			spn.addNumber(i + 1);
		std::cout << spn.longestSpan() << std::endl;
		spn.addNumber(20001);
		std::cout << "NO PRINT ! ! ! ! ! !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}

#include "Span.hpp"

int main()
{
	std::cout << "***********************Subject Test*****************" << std::endl;
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

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
	
	std::cout << "***********************Test 4***********************" << std::endl;
	try
	{
		Span spn(10);
		spn.addFullNumber();
		std::cout << spn.getNumber(5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

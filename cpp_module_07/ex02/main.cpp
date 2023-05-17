#include "Array.hpp"
#include <iostream>

int main()
{
	std::cout << "***********************Test 1***********************" << std::endl;
	try
	{
		Array<int> arr(5);

		std::cout << arr.size() << std::endl;
		std::cout << arr[3] << std::endl;
		std::cout << arr[10] << std::endl;
		std::cout << "NO PRINT ! ! ! ! ! !" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "***********************Test 2***********************" << std::endl;
	try
	{
		Array<float> arr(7);
		Array<float> copy_arr(arr);

		std::cout << arr.size() << std::endl;
		std::cout << copy_arr.size() << std::endl;
		std::cout << copy_arr[5] << std::endl;
		std::cout << copy_arr[10] << std::endl;
		std::cout << "NO PRINT ! ! ! ! ! !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "***********************Test 3***********************" << std::endl;
	try
	{
		Array<double> arr(10);
		Array<double> oper_arr;

		oper_arr = arr;
		std::cout << arr.size() << std::endl;
		std::cout << oper_arr.size() << std::endl;
		std::cout << oper_arr[4] << std::endl;
		std::cout << oper_arr[11] << std::endl;
		std::cout << "NO PRINT ! ! ! ! ! !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}

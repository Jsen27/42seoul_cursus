#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	try
	{
		std::vector<int> vec;
		for(int i = 0; i < 10; i++)
			vec.push_back(i * 2);
		std::cout << *(easyfind(vec, 4)) << std::endl;
		std::cout << *(easyfind(vec, 5)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::list<int> lt;
		for(int i = 0; i < 10; i++)
			lt.push_front(i * 3);
		std::cout << *(easyfind(lt, 9)) << std::endl;
		std::cout << *(easyfind(lt, 10)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::deque<int> dq;
		dq.push_back(1);
		dq.push_back(2);
		dq.push_back(3);
		std::cout << *(easyfind(dq, 1)) << std::endl;
		std::cout << *(easyfind(dq, 2)) << std::endl;
		std::cout << *(easyfind(dq, 99)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

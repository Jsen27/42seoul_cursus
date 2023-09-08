#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	std::cout << "------------Pointer test----------" << std::endl;
	Base* basePtr1 = generate();
	Base* basePtr2 = generate();
	Base* basePtr3 = generate();
	identify(basePtr1);
	identify(basePtr2);
	identify(basePtr3);

	std::cout << "------------Reference test----------" << std::endl;
	Base& baseRef1 = *basePtr1;
	Base& baseRef2 = *basePtr2;
	Base& baseRef3 = *basePtr3;
	identify(baseRef1);
	identify(baseRef2);
	identify(baseRef3);
	
	delete basePtr1;
	delete basePtr2;
	delete basePtr3;

	return 0;
}

Base* generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int randTime = std::rand() % 3;
	if (randTime == 0)
		return new A;
	else if (randTime == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is A Class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is B Class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is C Class" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "This is A Class" << std::endl;
		(void)a;
	}
	catch(const std::exception& e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "This is B Class" << std::endl;
		(void)b;
	}
	catch(const std::exception& e){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "This is C Class" << std::endl;
		(void)c;
	}
	catch(const std::exception& e){}
}

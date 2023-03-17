#include "Zombie.hpp"

void randomChump(std::string name);

int main()
{
	Zombie stack1("stack1_Zombie");
	Zombie* heap1 = new Zombie("heap1_Zombie");
	
	randomChump("stack2_Zombie");
	stack1.announce();
	heap1->announce();
	delete heap1;

	return 0;
}
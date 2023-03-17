#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* Horde;

	Horde = zombieHorde(9, "zombieboy");

	for (int i = 0; i < 9; i++)
		Horde[i].announce();

	delete[] Horde;
	
	return 0;
}
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* temp = new Zombie(name);
	return temp;
}
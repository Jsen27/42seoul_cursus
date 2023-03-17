#include "Zombie.hpp"

void Zombie::set_name(std::string name, char idx)
{
	this->name = name + idx;
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* tmp = new Zombie[N];

	for (int i = 0; i < N; i++)
		tmp[i].set_name(name, i + 1 + '0');

	return tmp;
}
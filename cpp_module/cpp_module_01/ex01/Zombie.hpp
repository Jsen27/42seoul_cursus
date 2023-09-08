#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		void announce();
		void set_name(std::string name, char idx);
		~Zombie();
};

#endif
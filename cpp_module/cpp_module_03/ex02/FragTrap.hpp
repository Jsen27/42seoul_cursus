#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &ref);
	FragTrap& operator=(const FragTrap &ref);
	void attack(const std::string &target);
	void highFivesGuys();
	~FragTrap();
};

#endif
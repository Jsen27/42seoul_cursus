#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &ref);
	ScavTrap& operator=(const ScavTrap &ref);
	void attack(const std::string &target);
	void guardGate();
	~ScavTrap();
};

#endif
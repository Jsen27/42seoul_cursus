#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#define DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &ref);
	DiamondTrap& operator=(const DiamondTrap &ref);
	void attack(const std::string &target);
	void whoAmI();

	~DiamondTrap();
};

#endif
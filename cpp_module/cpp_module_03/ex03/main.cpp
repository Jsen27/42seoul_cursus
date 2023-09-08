#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap kim("kim");
	DiamondTrap lee("lee");

	kim.whoAmI(); // DiamondTrap member function
	kim.guardGate(); // ScavTrap member function
	lee.whoAmI(); // DiamondTrap member function
	lee.highFivesGuys(); // FragTrap member function

	kim.attack("lee");
	lee.takeDamage(kim.getDamage());

	return 0;
}
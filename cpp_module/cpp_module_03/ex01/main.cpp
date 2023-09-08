#include "ScavTrap.hpp"

int main()
{
	ScavTrap kim("kim");
	ScavTrap lee("lee");

	kim.guardGate();

	kim.attack("lee"); // kim -> lee attack
	lee.takeDamage(kim.getDamage());
	lee.attack("kim"); // lee -> kim attack
	kim.takeDamage(lee.getDamage());
	kim.beRepaired(100); // kim repaired 100
	lee.attack("kim"); // lee -> kim attack
	kim.takeDamage(lee.getDamage());
	kim.attack("lee"); // kim -> lee attack
	lee.takeDamage(kim.getDamage()); 
	lee.beRepaired(99999);

	return 0;
}
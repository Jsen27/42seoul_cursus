#include "ClapTrap.hpp"

int main()
{
	ClapTrap kim("kim");
	ClapTrap lee("lee");

	kim.setDamage(5); // kim damage 5
	lee.setDamage(9); // lee damage 9
	kim.attack("lee"); // kim -> lee attack
	lee.takeDamage(kim.getDamage());
	lee.attack("kim"); // lee -> kim attack
	kim.takeDamage(lee.getDamage());
	kim.beRepaired(100); // kim repaired 100
	lee.attack("kim"); // lee -> kim attack
	kim.takeDamage(lee.getDamage());
	kim.attack("lee"); // kim -> lee attack
	lee.takeDamage(kim.getDamage()); // lee died
	lee.beRepaired(99999);

	return 0;
}

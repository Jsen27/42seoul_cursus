#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	unsigned int hit;
	unsigned int energy;
	unsigned int damage;

public:
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &ref);
	ClapTrap& operator=(const ClapTrap &ref);
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setDamage(unsigned int amount);
	unsigned int getDamage() const;

	virtual ~ClapTrap();
};

#endif
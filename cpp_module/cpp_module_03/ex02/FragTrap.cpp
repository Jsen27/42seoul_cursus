#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	this->hit = 100;
	this->energy = 10;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref.name)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = this->damage;
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
	ClapTrap(ref.name);
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = this->damage;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (this->hit == 0 || energy == 0)
		std::cout << "FragTrap " << this->name << " can't move" << std::endl;
	else{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energy--;
	}
}

void FragTrap::highFivesGuys()
{
	if (energy == 0)
		std::cout << "FragTrap " << this->name << " can't move" << std::endl;
	else
		std::cout << "FragTrap " << this->name << "'s positive high five request" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

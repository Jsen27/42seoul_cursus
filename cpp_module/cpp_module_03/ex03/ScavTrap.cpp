#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref.name)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = this->damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
	ClapTrap(ref.name);
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = this->damage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hit == 0 || energy == 0)
		std::cout << "ScavTrap " << this->name << " can't move" << std::endl;
	else{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energy--;
	}
}

void ScavTrap::guardGate()
{
	if (energy == 0)
		std::cout << "ScavTrap " << this->name << " can't move" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " now in Gatekepper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

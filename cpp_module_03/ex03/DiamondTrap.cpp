#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	name = ClapTrap::name;
	ClapTrap::name += "_clap_name";
	damage = 30;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
	ClapTrap::name += "_clap_name";
	damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) :ClapTrap(ref.name), FragTrap(ref.name), ScavTrap(ref.name), name(ref.name)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	ClapTrap::name += "_clap_name";
	damage = 30;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &ref)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = ref.damage;
	ClapTrap::name = ref.name + "_clap_name";
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	if (this->hit == 0 || energy == 0)
		std::cout << "DiamondTrap " << this->name << " can't move" << std::endl;
	else{
		std::cout << "DiamondTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energy--;
	}
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name is " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
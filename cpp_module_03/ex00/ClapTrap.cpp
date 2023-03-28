#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("no_name"), hit(10), energy(10), damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hit(10), energy(10), damage(0)
{
	std::cout << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) : name(ref.name), hit(ref.hit), energy(ref.energy), damage(ref.damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = ref.damage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit <= 0 || energy <= 0)
		std::cout << "ClapTrap " << this->name << " can't move" << std::endl;
	else{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->hit--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->energy <= 0)
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
	else{
		if (static_cast<int>(this->energy) - static_cast<int>(amount) < 0)
			this->energy = 0;
		else
			this->energy -= amount;
		std::cout << "ClapTrap " << this->name << " energy is " << energy << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit <= 0 || energy <= 0)
		std::cout << "ClapTrap " << this->name << " can't move" << std::endl;
	else{
		std::cout << "ClapTrap " << this->name << " repaired " << amount << " points of energy" << std::endl;
		this->hit--;
		this->energy += amount;
	}
}

void ClapTrap::setDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " set the damage to " << amount << std::endl;
	this->damage = amount;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
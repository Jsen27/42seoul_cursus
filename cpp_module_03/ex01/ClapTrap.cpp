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
	if (this->hit == 0 || energy == 0)
		std::cout << "ClapTrap " << this->name << " can't move" << std::endl;
	else{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit == 0)
		std::cout << this->name << " is already dead" << std::endl;
	else{
		if (static_cast<int>(this->hit) - static_cast<int>(amount) < 0)
			this->hit = 0;
		else
			this->hit -= amount;
		std::cout << this->name << " hit points is " << hit << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit == 0 || energy == 0)
		std::cout << this->name << " can't move" << std::endl;
	else{
		std::cout << this->name << " repaired " << amount << " points of hit" << std::endl;
		this->energy--;
		this->hit += amount;
	}
}

void ClapTrap::setDamage(unsigned int amount)
{
	std::cout << this->name << " set the damage to " << amount << std::endl;
	this->damage = amount;
}

unsigned int ClapTrap::getDamage() const
{
	return this->damage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}
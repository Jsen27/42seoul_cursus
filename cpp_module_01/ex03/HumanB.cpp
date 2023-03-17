#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon) : name(name), weapon(weapon)
{

}

HumanB::HumanB(std::string name) : name(name)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack() const
{
	std::cout << this->weapon->getType() << std::endl;
}
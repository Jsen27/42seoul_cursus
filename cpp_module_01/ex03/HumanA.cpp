#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{

}

void HumanA::attack() const
{
	std::cout << this->weapon.getType() << std::endl;
}
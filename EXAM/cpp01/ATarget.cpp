#include "ATarget.hpp"

ATarget::ATarget()
{}

ATarget::ATarget(std::string const& type)
: type(type)
{

}

ATarget::ATarget(ATarget const& ref)
: type(ref.getType())
{

}

ATarget& ATarget::operator=(ATarget const& ref)
{
	type = ref.getType();
	return *this;
}

ATarget::~ATarget()
{}

std::string const& ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(ASpell const& ref) const
{
	std::cout << type << " has been " << ref.getEffects() << "!" << std::endl;
}
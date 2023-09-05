#include "ASpell.hpp"

ASpell::ASpell()
{}

ASpell::ASpell(std::string const& name, std::string const& effects)
: name(name), effects(effects)
{

}

ASpell::ASpell(ASpell const& ref)
: name(ref.getName()), effects(ref.getEffects())
{

}

ASpell& ASpell::operator=(ASpell const& ref)
{
	name = ref.getName();
	effects = ref.getEffects();
	return *this;
}

ASpell::~ASpell()
{}

std::string const& ASpell::getName() const
{
	return name;
}

std::string const& ASpell::getEffects() const
{
	return effects;
}

void ASpell::launch(ATarget const& ref) const
{
	ref.getHitBySpell(*this);
}
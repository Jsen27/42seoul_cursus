#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
:ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh::~Fwoosh()
{

}

ASpell* Fwoosh::clone() const
{
	ASpell* temp = new Fwoosh();
	return temp;
}
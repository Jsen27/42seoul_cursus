#include "Fireball.hpp"

Fireball::Fireball()
: ASpell("Fireball", "burnt to a crisp")
{

}

Fireball::~Fireball()
{

}

ASpell* Fireball::clone() const
{
	ASpell* temp = new Fireball();
	return temp;
}
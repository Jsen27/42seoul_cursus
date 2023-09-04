#pragma once

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class Fireball : public ASpell
{
public:
	Fireball();
	virtual ~Fireball();
	ASpell* clone() const;
};


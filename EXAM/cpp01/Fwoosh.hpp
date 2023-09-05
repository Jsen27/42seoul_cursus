#pragma once

#include "ASpell.hpp"
#include <iostream>

class Fwoosh : public ASpell
{
public:
	Fwoosh();
	virtual ~Fwoosh();
	ASpell* clone() const;
};

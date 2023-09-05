#pragma once

#include "ATarget.hpp"
#include <iostream>

class ATarget;

class ASpell
{
private:
	std::string name;
	std::string effects;

public:
	ASpell();
	ASpell(std::string const& name, std::string const& effects);
	ASpell(ASpell const& ref);
	ASpell& operator=(ASpell const& ref);
	virtual ~ASpell();

	std::string const& getName() const;
	std::string const& getEffects() const;

	virtual ASpell* clone() const = 0;

	void launch(ATarget const& ref) const;
};

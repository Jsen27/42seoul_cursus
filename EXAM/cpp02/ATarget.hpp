#pragma once

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class ATarget
{
private:
	std::string type;

public:
	ATarget();
	ATarget(std::string const& type);
	ATarget(ATarget const& ref);
	ATarget& operator=(ATarget const& ref);
	virtual ~ATarget();

	std::string const& getType() const;

	virtual ATarget* clone() const = 0;

	void getHitBySpell(ASpell const& ref) const;
};

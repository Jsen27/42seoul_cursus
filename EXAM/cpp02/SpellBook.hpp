#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <map>

class SpellBook
{
private:
	std::map<std::string, ASpell*> book;
	
	SpellBook(SpellBook const& ref);
	SpellBook& operator=(SpellBook const& ref);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const& spell);
	ASpell* createSpell(std::string const& spell);
};
#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <map>

class ASpell;

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
	void forgetSpell(std::string const& spell_name);
	ASpell* createSpell(std::string const& spell_name);

};
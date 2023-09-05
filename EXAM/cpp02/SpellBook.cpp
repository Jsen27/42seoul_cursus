#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::iterator it = book.begin();
	while (it != book.end()){
		delete it->second;
		it++;
	}
	book.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	book.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const& spell_name)
{
	std::map<std::string, ASpell*>::iterator it = book.find(spell_name);
	if (it != book.end()){
		delete it->second;
		book.erase(spell_name);
	}
}

ASpell* SpellBook::createSpell(std::string const& spell_name)
{
	if (book.find(spell_name) != book.end())
		return book[spell_name];
	return NULL;
}
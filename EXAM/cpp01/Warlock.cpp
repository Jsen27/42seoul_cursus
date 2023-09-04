#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
: name(name), title(title)
{
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!\n";
	std::map<std::string, ASpell*>::iterator it_1 = book.begin();
	std::map<std::string, ASpell*>::iterator it_2 = book.end();
	while (it_1 != it_2){
		delete it_1->second;
		it_1++;
	}
	book.clear();
}

std::string const &Warlock::getName() const
{
	return name;
}

std::string const &Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		book.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string const& spell_name)
{
	std::map<std::string, ASpell*>::iterator it = book.find(spell_name);
	if (it != book.end())
		delete it->second;
	book.erase(spell_name);
}

void Warlock::launchSpell(std::string const& spell_name, ATarget const& ref)
{
	if (book.find(spell_name) != book.end()){
		ASpell* spell = book[spell_name];
	if (spell)
		spell->launch(ref);
	}
}
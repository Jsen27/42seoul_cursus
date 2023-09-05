#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <map>

class ASpell;

class Warlock
{
private:
	std::string name;
	std::string title;
	std::map<std::string, ASpell*> book;

	Warlock();
	Warlock(Warlock const& ref);
	Warlock& operator=(Warlock const& ref);

public:
	Warlock(std::string const& name, std::string const& title);
	~Warlock();

	std::string const& getName() const;
	std::string const& getTitle() const;

	void setTitle(std::string const& title);
	void introduce() const;

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const& spell_name);
	void launchSpell(std::string const& spell_name, ATarget const& ref);

};

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
: name(name), title(title)
{
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!\n";
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

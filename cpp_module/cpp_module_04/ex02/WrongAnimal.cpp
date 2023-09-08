#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) : type(ref.type)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal say nothing, this message is wrong" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

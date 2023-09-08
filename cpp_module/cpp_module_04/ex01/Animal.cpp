#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &ref) : type(ref.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &ref)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal say nothing, this message is wrong" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

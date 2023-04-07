#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	Animal::type = "Dog";
}

Dog::Dog(const Dog &ref)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	Animal::type = ref.type;
}

Dog& Dog::operator=(const Dog &ref)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	Animal::type = ref.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog say : bow-wow!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

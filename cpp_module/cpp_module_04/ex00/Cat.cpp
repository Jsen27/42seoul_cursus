#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	Animal::type = "Cat";
}

Cat::Cat(const Cat &ref)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	Animal::type = ref.type;
}

Cat& Cat::operator=(const Cat &ref)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	Animal::type = ref.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat say : meow..." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

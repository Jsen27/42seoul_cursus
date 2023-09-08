#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	Animal::type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &ref)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	Animal::type = ref.type;
	brain = new Brain(*ref.brain);
}

Cat& Cat::operator=(const Cat &ref)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	Animal::type = ref.type;
	*brain = *ref.brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat say : meow..." << std::endl;
}

std::string Cat::getbrain(const int index) const
{
	return brain->getIdeas(index);
}

Cat::~Cat()
{	
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;
}

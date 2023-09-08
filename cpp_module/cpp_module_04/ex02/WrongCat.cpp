#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	WrongAnimal::type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &ref)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	WrongAnimal::type = ref.type;
}

WrongCat& WrongCat::operator=(const WrongCat &ref)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	WrongAnimal::type = ref.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat say : bow-wow!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

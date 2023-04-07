#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &ref);
	Dog& operator=(const Dog &ref);
	void makeSound() const;
	~Dog();
};

#endif

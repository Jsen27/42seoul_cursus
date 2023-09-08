#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &ref);
	Animal& operator=(const Animal &ref);
	virtual void makeSound() const = 0;
	std::string getType() const;
	virtual ~Animal();
};

#endif

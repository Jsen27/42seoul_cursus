#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &ref);
	Dog& operator=(const Dog &ref);
	void makeSound() const;
	std::string getBrain(const int index) const;
	~Dog();
};

#endif

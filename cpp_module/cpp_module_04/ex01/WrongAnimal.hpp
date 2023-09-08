#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &ref);
	WrongAnimal& operator=(const WrongAnimal &ref);
	void makeSound() const;
	std::string getType() const;
	virtual ~WrongAnimal();
};

#endif

#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &ref);
	WrongCat& operator=(const WrongCat &ref);
	void makeSound() const;
	~WrongCat();
};

#endif

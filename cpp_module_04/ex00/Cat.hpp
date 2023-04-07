#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &ref);
	Cat& operator=(const Cat &ref);
	void makeSound() const;
	~Cat();
};

#endif

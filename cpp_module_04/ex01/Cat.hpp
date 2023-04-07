#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &ref);
	Cat& operator=(const Cat &ref);
	void makeSound() const;
	std::string getbrain(const int index) const;
	~Cat();
};

#endif

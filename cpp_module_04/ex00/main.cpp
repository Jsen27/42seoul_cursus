#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
/*				subject test				*/

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

/*					my test					*/

	std::cout << std::endl << std::endl << "			my test" << std::endl << std::endl << std::endl;

	const WrongAnimal *a = new WrongCat();

	std::cout << a->getType() << " " << std::endl;
	a->makeSound();

	delete a;

	return 0;
}

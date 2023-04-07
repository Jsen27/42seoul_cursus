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

	const Animal* animal[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
		delete animal[i];


	std::cout << std::endl << std::endl << "			my test2" << std::endl << std::endl << std::endl;


	const Cat* cat = new Cat();
	Cat cat22;

	std::cout << cat->getbrain(41) << std::endl;
	std::cout << cat22.getbrain(41) << std::endl;

	cat22 = *cat;
	std::cout << cat22.getbrain(41) << std::endl;

	delete cat;

	return 0;
}

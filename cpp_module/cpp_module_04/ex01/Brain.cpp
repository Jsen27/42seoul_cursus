#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = "ideas";
		if (i < 10)
			ideas[i] += i + '0';
		else
		{
			ideas[i] += (i / 10) + '0';
			ideas[i] += (i % 10) + '0';
		}	
	}
}

Brain::Brain(const Brain &ref)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = ref.ideas[i];
}

Brain& Brain::operator=(const Brain &ref)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = ref.ideas[i];
	return *this;
}

std::string Brain::getIdeas(const int index) const
{
	return ideas[index];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

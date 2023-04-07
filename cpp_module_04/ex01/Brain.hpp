#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &ref);
	Brain& operator=(const Brain &ref);
	std::string getIdeas(const int index) const;
	~Brain();
};

#endif

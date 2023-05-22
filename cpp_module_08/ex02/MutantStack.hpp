#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	MutantStack(const MutantStack& ref) {(void)ref};
	MutantStack& operator=(const MutantStack& ref) {return *this};
	~MutantStack() {};

};

#endif

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	MutantStack(const MutantStack& ref) {(void)ref;};
	MutantStack& operator=(const MutantStack& ref) {(void)ref; return *this;};
	~MutantStack() {};

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin() {return this->c.begin();};
	iterator end() {return this->c.end();};
};

#endif

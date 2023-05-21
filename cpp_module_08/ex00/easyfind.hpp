#ifndef _EASYFIND_HPP
#define _EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <class T>
typename T::iterator easyfind(T& t1, int num)
{
	typename T::iterator iter;
	iter = std::find(t1.begin(), t1.end(), num);
	if (iter == t1.end())
		throw std::runtime_error("The value is not in the container");
	return iter;
}

#endif

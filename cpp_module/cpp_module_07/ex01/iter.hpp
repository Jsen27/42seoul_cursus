#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*fn)(T))
{
	for (size_t i = 0; i < length; i++){
		fn(array[i]);
	}
}

template <typename T>
void print(T tmp)
{
	std::cout << tmp << std::endl;
}

#endif

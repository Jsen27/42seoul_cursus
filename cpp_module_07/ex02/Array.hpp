#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
private:
	T* arr;
	unsigned int length;
public:
	Array();
	Array(const unsigned int num);
	Array(const Array& ref);
	~Array();
	
	Array& operator=(const Array& ref);
	T operator[](const unsigned int idx);

	size_t size()const;
};

template <typename T>
Array<T>::Array() : length(0)
{
	arr = NULL;
}

template <typename T>
Array<T>::Array(const unsigned int num) : length(num)
{
	arr = new T[num];
}

template <typename T>
Array<T>::Array(const Array& ref) : length(ref.length)
{
	arr = new T[length];
	for(unsigned int i = 0; i < length; i++)
		arr[i] = ref.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	if (this != &ref){
		delete[] arr;
		length = ref.length;
		arr = new T[length];
		for(unsigned int i = 0; i < length; i++)
			arr[i] = ref.arr[i];
	}
	return *this;
}

template <typename T>
T Array<T>::operator[](const unsigned int idx)
{
	if (idx < 0 || idx > length)
		throw std::out_of_range("out of range !");
	return arr[idx];
}

template <typename T>
size_t Array<T>::size()const
{
	return static_cast<size_t>(length);
}

#endif

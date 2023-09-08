#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

template <typename T>
void swap(T& ptr1, T& ptr2)
{
	T temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

template <class T>
T min(T num1, T num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

template <class T>
T max(T num1, T num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}

#endif

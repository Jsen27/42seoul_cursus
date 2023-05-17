#include "iter.hpp"
#include <iostream>

int main()
{
	int array[5];

	for (int i = 0; i < 5; i++)
		array[i] = i + 1;
	::iter(array, 5, print);
	
	char str[6] = "apple";
	::iter(str, 5, print);

	return 0;
}

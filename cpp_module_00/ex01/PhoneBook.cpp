#include "main.hpp"

void PhoneBook::Addarray()
{
	if (idx == 8)
		idx = 0;
	array[idx].Addcontact();
}

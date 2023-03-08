#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->idx = 0;
}

void PhoneBook::Addarray()
{
	if (idx == 8)
		idx = 0;
	array[idx].Addcontact();
}

#include "Serializer.hpp"

int main(int argc, char** argv)
{
	Data prev;
	Data *next;
	uintptr_t ptr;

	if (argc != 2)
	{
		std::cout << "Usage : ./serializer [string]" << std::endl;
		return 1;
	}

	prev.name = argv[1];
	std::cout << "prev : " << prev.name << std::endl;

	ptr = Serializer::serialize(&prev);
	std::cout << "ptr : " << ptr << std::endl;

	next = Serializer::deserialize(ptr);
	std::cout << "next : " << next->name << std::endl;

	std::cout << "prev address    : " << &prev << std::endl;
	std::cout << "address of next : " << next << std::endl;

	return 0;
}

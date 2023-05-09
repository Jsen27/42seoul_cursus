#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <stdint.h>
#include <iostream>

struct Data
{
	std::string name;
};

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer& ref);
	Serializer& operator=(const Serializer& ref);
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif

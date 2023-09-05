#pragma once

#include "ATarget.hpp"
#include <iostream>

class Dummy : public ATarget
{
public:
	Dummy();
	virtual ~Dummy();
	ATarget* clone() const;
};

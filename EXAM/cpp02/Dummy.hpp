#pragma once

#include "ATarget.hpp"
#include <iostream>

class ATarget;

class Dummy : public ATarget
{
public:
	Dummy();
	virtual ~Dummy();
	ATarget* clone() const;
};

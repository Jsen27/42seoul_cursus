#pragma once

#include "ATarget.hpp"
#include <iostream>

class ATarget;

class Dummy : public ATarget
{
public:
	Dummy();
	~Dummy();
	virtual ATarget* clone() const;
};

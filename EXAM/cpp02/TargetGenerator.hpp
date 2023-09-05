#pragma once

#include "ATarget.hpp"
#include <iostream>
#include <map>

class TargetGenerator
{
private:
	std::map<std::string, ATarget*> targen;
	TargetGenerator(TargetGenerator const& ref);
	TargetGenerator& operator=(TargetGenerator const& ref);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const& target_name);
	ATarget* createTarget(std::string const& target_name);

};

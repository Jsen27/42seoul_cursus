#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::iterator it = targen.begin();
	while (it != targen.end()){
		delete it->second;
		it++;
	}
	targen.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	targen.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const& target_name)
{
	std::map<std::string, ATarget*>::iterator it = targen.find(target_name);
	if (it != targen.end()){
		delete it->second;
		targen.erase(target_name);
	}
}

ATarget* TargetGenerator::createTarget(std::string const& target_name)
{
	if (targen.find(target_name) != targen.end())
		return targen[target_name];
	return NULL;
}
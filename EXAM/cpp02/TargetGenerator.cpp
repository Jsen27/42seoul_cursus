#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::iterator it_1 = targetmap.begin();
	while (it_1 != targetmap.end()){
		delete it_1->second;
		it_1++;
	}
	targetmap.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	targetmap.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const& target)
{
	std::map<std::string, ATarget*>::iterator it = targetmap.find(target);
	if (it != targetmap.end()){
		delete it->second;
		targetmap.erase(target);
	}
}

ATarget* TargetGenerator::createTarget(std::string const& target)
{
	if (targetmap.find(target) != targetmap.end()){
		return targetmap[target];
	}
	return NULL;
}
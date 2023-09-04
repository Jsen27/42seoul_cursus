#include "Dummy.hpp"

Dummy::Dummy()
: ATarget("Target Practice Dummy")
{

}

Dummy::~Dummy()
{

}

ATarget* Dummy::clone() const
{
	ATarget* temp = new Dummy();
	return temp;
}

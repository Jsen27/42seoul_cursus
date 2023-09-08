#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <iostream>

class Weapon
{
	private:
		std::string type;
	
	public:
		Weapon(std::string type);
		void setType(const std::string type);
		const std::string &getType() const;
};

#endif
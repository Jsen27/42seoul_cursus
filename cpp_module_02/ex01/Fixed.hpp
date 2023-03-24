#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int bit = 8;

	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &ref);
		Fixed& operator=(const Fixed &ref);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt() const;
		~Fixed();
};

std::ostream& operator<<(std::ostream &os, const Fixed &ref);


#endif
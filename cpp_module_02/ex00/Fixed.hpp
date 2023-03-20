#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int bit = 8;

	public:
		Fixed();
		Fixed(const Fixed &ref);
		Fixed& operator=(const Fixed &ref);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);	
};

#endif
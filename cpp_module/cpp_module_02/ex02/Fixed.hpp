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
	
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt() const;

		Fixed& operator=(const Fixed &ref);

		bool operator>(const Fixed &ref) const;
		bool operator<(const Fixed &ref) const;
		bool operator>=(const Fixed &ref) const;
		bool operator<=(const Fixed &ref) const;
		bool operator==(const Fixed &ref) const;
		bool operator!=(const Fixed &ref) const;

		Fixed operator+(const Fixed &ref) const;
		Fixed operator-(const Fixed &ref) const;
		Fixed operator*(const Fixed &ref) const;
		Fixed operator/(const Fixed &ref) const;

		Fixed &operator++();
		const Fixed operator++(int);
		Fixed &operator--();
		const Fixed operator--(int);

		static Fixed &min(Fixed &ref1, Fixed &ref2);
		static const Fixed &min(const Fixed &ref1, const Fixed &ref2);
		static Fixed &max(Fixed &ref1, Fixed &ref2);
		static const Fixed &max(const Fixed &ref1, const Fixed &ref2);

		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& ref);

#endif
#ifndef _POINT_HPP_
#define _POINT_HPP_

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &ref);
		
		Point &operator=(const Point &ref);
		
		Fixed getX() const;
		Fixed getY() const;

		~Point();
};

#endif

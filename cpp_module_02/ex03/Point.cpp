#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float x, const float y) : x(x), y(y)
{

}

Point::Point(const Point &ref) : x(ref.getX()), y(ref.getY())
{
	
}

Point &Point::operator=(const Point &ref)
{
	const_cast<Fixed &>(x) = ref.getX();
	const_cast<Fixed &>(y) = ref.getY();
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

Point::~Point()
{

}
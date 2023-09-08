#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point	a(5, 5);
	Point	b(2, 9);
	Point	c(0, 5);
	Point	p(3, 7);
	Point	p2(4, 7);

	std::cout << "Point a X = " << a.getX() << ", Y = " << a.getY() << std::endl;
	std::cout << "Point b X = " << b.getX() << ", Y = " << b.getY() << std::endl;
	std::cout << "Point c X = " << c.getX() << ", Y = " << c.getY() << std::endl;
	std::cout << "Point p X = " << p.getX() << ", Y = " << p.getY() << std::endl;
	std::cout << "Point p2 X = " << p2.getX() << ", Y = " << p2.getY() << std::endl;
	
	if (bsp(a, b, c, p))
		std::cout << "p is in the triangle" << std::endl;
	else
		std::cout << "p is out of the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;
		
	return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool ret = false;

	if ((a.getY() > point.getY()) != (b.getY() > point.getY()))
	{
		if (((b.getX() - a.getX()) * ((point.getY() - a.getY()) / (b.getY() - a.getY())) + a.getX()) >= point.getX())
		{
			if (ret)
				ret = false;
			else
				ret = true;
		}
	}
	if ((a.getY() > point.getY()) != (c.getY() > point.getY()))
	{
		if (((c.getX() - a.getX()) * ((point.getY() - a.getY()) / (c.getY() - a.getY())) + a.getX()) >= point.getX())
		{
			if (ret)
				ret = false;
			else
				ret = true;
		}
	}
	if ((b.getY() > point.getY()) != (c.getY() > point.getY()))
	{
		if (((c.getX() - b.getX()) * ((point.getY() - b.getY()) / (c.getY() - b.getY())) + b.getX()) >= point.getX())
		{
			if (ret)
				ret = false;
			else
				ret = true;
		}
	}
	return (ret);
}

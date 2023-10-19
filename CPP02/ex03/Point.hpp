#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private	:
				const Fixed _x;
				const Fixed _y;

	public	:
				Point(void);
				Point(const float x, const float y);
				Point(const Point &copy);
				~Point();

				Point&	operator= (const Point& rhs);
				const Fixed get_x() const;
				const Fixed get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

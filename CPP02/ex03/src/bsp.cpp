#include "Fixed.hpp"
#include "Point.hpp"

float t_area(Point const a, Point const b, Point const c);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float abc(t_area(a, b, c));
	float abp(t_area(a, b, point));
	float apc(t_area(a, point, c));
	float pbc(t_area(point, b, c));
	return (abc == (abp + apc + pbc));
}


float t_area(Point const a, Point const b, Point const c)
{
	float area((a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat())
				+ b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat())
				+ c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat())) / 2);
	if (area < 0)
		area *= -1;
	return (area);
}
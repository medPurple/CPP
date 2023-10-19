#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){}

Point::Point(const float x, const float y) : _x(x), _y(y){}

Point::Point(const Point &copy) : _x(copy.get_x()), _y(copy.get_y()){*this = copy;}

Point::~Point(void){}

Point &Point::operator=(const Point& rhs){
	if (this != &rhs)
	{
		(Fixed) this->_x = rhs.get_x();
		(Fixed) this->_y = rhs.get_y();
	}
	return (*this);
}

const Fixed	Point::get_x(void) const{
	return (this->_x);
}

const Fixed	Point::get_y(void) const{
	return (this->_y);
}
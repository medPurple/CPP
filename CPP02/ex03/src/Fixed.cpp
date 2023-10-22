#include "Fixed.hpp"
#include <cmath>

// Constructeurs

Fixed::Fixed() //Default
{
    setRawBits(0);
}

Fixed::Fixed(const int i) // Parametric
{
    this->_value = (i << this->_FBit);
}

Fixed::Fixed(const float i) // Parametric
{
    this->_value = roundf(i * (1 << this->_FBit));
}

Fixed::Fixed(const Fixed& obj) // Copy
{
    *this = obj;
}




// Assignateur

Fixed& Fixed::operator=(const Fixed& obj) // =
{
    setRawBits(obj.getRawBits());
    return (*this);
}

bool    Fixed::operator> (const Fixed& rhs) const // >
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool    Fixed::operator< (const Fixed& rhs) const // <
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool    Fixed::operator>= (const Fixed& rhs) const // >=
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool    Fixed::operator<= (const Fixed& rhs) const // <=
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool    Fixed::operator== (const Fixed& rhs) const // ==
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool    Fixed::operator!= (const Fixed& rhs) const // !=
{
    return (this->getRawBits() != rhs.getRawBits());
}


Fixed	Fixed::operator+(const Fixed& rhs) const // +
{
    Fixed result;

    result.setRawBits(this->getRawBits() + rhs.getRawBits());
    return (result);
}

Fixed	Fixed::operator- (const Fixed& rhs) const // -
{
    Fixed result;

    result.setRawBits(this->getRawBits() - rhs.getRawBits());
    return (result);
}

Fixed	Fixed::operator* (const Fixed& rhs) const // *
{
    Fixed result(this->toFloat() * rhs.toFloat());
    return (result);
}

Fixed	Fixed::operator/ (const Fixed& rhs) const // /
{
    Fixed result(this->toFloat() / rhs.toFloat());
    return (result);
}


Fixed   &Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}

Fixed   &Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed old(*this);

    this->_value++;
    return (old);
}

Fixed   Fixed::operator--(int)
{
    Fixed old(*this);

    this->_value--;
    return (old);
}


// Destructeur

Fixed::~Fixed()
{
}




// Fonction

void Fixed::setRawBits(const int nb)
{
    this->_value = nb;
}

int Fixed::getRawBits() const
{
    return (this->_value);
}

float   Fixed::toFloat(void) const
{
    return ((float)this->_value / (float)(1 << this->_FBit));
}

int     Fixed::toInt(void) const
{
    return (this->_value >> this->_FBit);
}

Fixed&       Fixed::min(Fixed &lhs, Fixed &rhs)
{
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

const Fixed& Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

Fixed&       Fixed::max(Fixed &lhs, Fixed &rhs)
{
    if (lhs < rhs)
        return (rhs);
    return (lhs);
}

const Fixed&	Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
    if (lhs < rhs)
        return (rhs);
    return (lhs);
}



std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
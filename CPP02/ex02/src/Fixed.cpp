#include "Fixed.hpp"
#include <cmath>

// Constructeurs

Fixed::Fixed() //Default
{
    std::cout << "[Default]\tConstructeur called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const int i) // Parametric
{
    std::cout << "[Parametric]\tConstructeur called" << std::endl;
    this->_value = (i << this->_FBit);
}

Fixed::Fixed(const float i) // Parametric
{
    std::cout << "[Parametric]\tConstructeur called" << std::endl;
    this->_value = roundf(i * (1 << this->_FBit));
}

Fixed::Fixed(const Fixed& obj) // Copy
{
    std::cout << "[Copy]\tconstructor called" << std::endl;
    *this = obj;
}




// Assignateur

Fixed& Fixed::operator=(const Fixed& obj) // =
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    setRawBits(obj.getRawBits());
    return (*this);
}

bool    Fixed::operator> (const Fixed& rhs) const // >
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    return (this->getRawBits() > rhs.getRawBits());
}

bool    Fixed::operator< (const Fixed& rhs) const // <
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    return (this->getRawBits() < rhs.getRawBits());
}

bool    Fixed::operator>= (const Fixed& rhs) const // >=
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    return (this->getRawBits() >= rhs.getRawBits());
}

bool    Fixed::operator<= (const Fixed& rhs) const // <=
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    return (this->getRawBits() <= rhs.getRawBits());
}

bool    Fixed::operator== (const Fixed& rhs) const // ==
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    return (this->getRawBits() == rhs.getRawBits());
}

bool    Fixed::operator!= (const Fixed& rhs) const // !=
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    return (this->getRawBits() != rhs.getRawBits());
}


Fixed	Fixed::operator+(const Fixed& rhs) const // +
{
    return (this->_value + rhs._value);
}

Fixed	Fixed::operator- (const Fixed& rhs) const // -
{
    return (this->_value - rhs._value);
}

Fixed	Fixed::operator* (const Fixed& rhs) const // *
{
    return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/ (const Fixed& rhs) const // /
{
    return (this->toFloat() / rhs.toFloat());
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
    std::cout << "[Default]\tDestructor called" << std::endl;
}




// Fonction

void Fixed::setRawBits(const int nb)
{
     std::cout << "[Fonction]\tsetRawbits called" << std::endl;

    this->_value = nb;
}

int Fixed::getRawBits() const
{
    std::cout << "[Fonction]\tgetRawBits called" << std::endl;

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
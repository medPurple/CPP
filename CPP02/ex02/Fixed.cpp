#include "Fixed.hpp"
#include <cmath>

// Constructeurs

Fixed::Fixed()
{
    std::cout << "[Default]\tConstructeur called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const int i)
{
    std::cout << "[Parametric]\tConstructeur called" << std::endl;
    this->_value = (i << this->_FBit);
}

Fixed::Fixed(const float i)
{
    std::cout << "[Parametric]\tConstructeur called" << std::endl;
    this->_value = roundf(i * (1 << this->_FBit));
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << "[Copy]\tconstructor called" << std::endl;
    *this = obj;
}




// Assignateur

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "[Operator]\tassignment called" << std::endl;
    setRawBits(obj.getRawBits());
    return (*this);
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

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
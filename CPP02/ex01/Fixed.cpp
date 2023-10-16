#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Constructeur called" << std::endl;
    setRawBits(0);
}










Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(obj.getRawBits());
    return (*this);
} 

void Fixed::setRawBits(const int nb)
{
     std::cout << "setRawbits called" << std::endl;

    this->value = nb;
}


int Fixed::getRawBits() const
{
    std::cout << "getRawBits called" << std::endl;

    return (this->value);
}
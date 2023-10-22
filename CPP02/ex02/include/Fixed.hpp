#pragma once

#include <iostream>


class Fixed{

    public  :
                Fixed();
                Fixed(const int i);
                Fixed(const float i);
                Fixed( const Fixed& copy);
                ~Fixed();

                Fixed&	operator= (const Fixed& rhs);

                bool    operator> (const Fixed& rhs) const;
                bool    operator< (const Fixed& rhs) const;
                bool    operator>= (const Fixed& rhs) const;
                bool    operator<= (const Fixed& rhs) const;
                bool    operator== (const Fixed& rhs) const;
                bool    operator!= (const Fixed& rhs) const;

                Fixed	operator+ (const Fixed& rhs) const;
                Fixed	operator- (const Fixed& rhs) const;
                Fixed	operator* (const Fixed& rhs) const;
                Fixed	operator/ (const Fixed& rhs) const;

                Fixed&	operator++(void);
                Fixed	operator++(int);
                Fixed&	operator--(void);
                Fixed	operator--(int);

                

                int     getRawBits( void ) const;
                void    setRawBits( int const raw );
                float   toFloat(void) const;
                int     toInt(void) const;

                static Fixed&       min(Fixed &lhs, Fixed &rhs);
                static const Fixed& min(const Fixed &lhs, const Fixed &rhs);
                static Fixed&       max(Fixed &lhs, Fixed &rhs);
                static const Fixed&	max(const Fixed &lhs, const Fixed &rhs);
                
    private :
                int _value;
                static const int _FBit = 8;

};

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);
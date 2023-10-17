#pragma once

#include <iostream>


class Fixed{

    public  :
                Fixed();
                Fixed(const int i);
                Fixed(const float i);
                Fixed( Fixed const & copy);
                ~Fixed();

                Fixed & operator = (Fixed const & rhs);

                int     getRawBits( void ) const;
                void    setRawBits( int const raw );
                float   toFloat(void) const;
                int     toInt(void) const;
                
    private :
                int _value;
                static const int _FBit = 8;

};

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);
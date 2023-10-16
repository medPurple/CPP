#pragma once

#include <iostream>


class Fixed{

    public  :
                Fixed();
                Fixed(const Fixed&);
                ~Fixed();
                Fixed& operator = (const Fixed&);

                int getRawBits( void ) const;
                void setRawBits( int const raw );
                
    private :
                int value;
                static const int nb = 8;

};
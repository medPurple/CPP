#pragma once

#include <iostream>


class Fixed{

    public  :
                Fixed();
                Fixed(const int i);
                Fixed(const float i);
                Fixed(const Fixed&);
                ~Fixed();
                Fixed& operator = (const Fixed&);

                int     getRawBits( void ) const;
                void    setRawBits( int const raw );
                float   toFloat(void);
                int     toInt(void);
                
    private :
                int value;
                static const int nb = 8;

};
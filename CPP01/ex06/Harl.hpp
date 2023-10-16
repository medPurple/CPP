#pragma once

# include <string.h>
# include <iostream>


class Harl{

    private :
                void _debug();
                void _info();
                void _warning();
                void _error();

    public  :
                Harl();
                ~Harl();

                void complain(std::string str);
};
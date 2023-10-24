#include "../include/Harl.hpp"

int main (int ac, char **av)
{
    Harl test;
    if (ac == 2)
        test.complain(av[1]);
    return(0);
}
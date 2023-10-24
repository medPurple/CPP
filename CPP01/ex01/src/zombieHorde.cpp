#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 1)
    {
        std::cout << "Horde need 1 or more zombie" << std::endl;
        return (NULL);
    }
    Zombie *tmp = new Zombie[N];
    if (!tmp)
    {
        std::cout << "Failed to create a horde" << std::endl;
        return  (NULL);
    }
    for (int k = 0; k < N; k++)
        tmp[k]._setname(name);
    return (tmp);
}


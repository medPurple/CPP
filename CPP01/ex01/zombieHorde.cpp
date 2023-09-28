#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    std::string str;

    if (N < 1)
        return (std::cout << "Horde need 1 or more zombie" << std::endl; NULL);
    Zombie *tmp = new Zombie[N];
    if (!tmp)
        return (std::cout << "Failed to create a horde" << std::endl; NULL);
    for (int k = 0; k < N; k++)
    {
        str.append(name);
        str.append(" [");
        str.append(std::to_string(k));
        str.append("]\n");
        tmp[k]._setname(str);
    }
    return (tmp);
}


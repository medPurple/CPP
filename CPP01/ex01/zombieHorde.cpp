#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    std::string str;
    for (int k = 0; k < N; k++)
    {
        str.append(name);
        str.append(" [");
        str.append(std::to_string(k));
        str.append("]\n");
        Zombie *tmp = new Zombie(str);
    }
}
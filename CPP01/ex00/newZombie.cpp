#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *tmp = new Zombie(name);
    tmp->annonce();
    return (tmp);
}
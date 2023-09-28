#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << CREATION_MSG << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << SUPPRESSION_MSG << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}

void    Zombie::_setname(std::string name)
{
    this->name = name;
}
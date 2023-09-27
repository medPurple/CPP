#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << this->name << CREATION_MSG << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << SUPPRESSION_MSG << std::endl;
}

void    Zombie::annonce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}
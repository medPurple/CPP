#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#define CREATION_MSG " the undead appear\n"
#define SUPPRESSION_MSG " the undead disappear\n"

#include <string>
#include <iostream>


class Zombie
{
    private :
                std::string name;
    public  :
                Zombie();
                ~Zombie();
                void announce(void);
                void _setname(std::string name);
};
Zombie* newZombie(std::string name );
Zombie* zombieHorde( int N, std::string name );
#endif
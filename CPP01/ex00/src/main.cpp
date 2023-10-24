#include "../include/Zombie.hpp"

int main(void)
{
    std::cout << "\tStarting apocalypse\n\n";
    Zombie *zombar = newZombie("Debilos");
    randomChump("Nullos");
    delete zombar;
    return (0);
}
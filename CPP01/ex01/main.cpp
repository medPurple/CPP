#include "Zombie.hpp"

int main(void)
{
    std::cout << "\tStarting apocalypse\n\n";
    Zombie *zombar = new Zombie("Debilos");
    randomChump("Nullos");
    delete zombar;
    return (0);
}
#include "../include/Zombie.hpp"

int main(void)
{
    Zombie *horde;
    int amount = 8;
    if (amount > 2147483647 || amount < -2147483648)
    {
        std::cout << "Max int limit\n";
        return (0);
    }
    std::cout << "\tStarting apocalypse\n\n";
    horde = zombieHorde(amount, "debilos");
    if (horde == NULL)
        return (1);
    for (int i = 0; i < amount; i++)
        horde[i].announce();
    delete[] horde;
    horde = NULL;
    return (0);
}
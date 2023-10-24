#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	ClapTrap p1("BOB");
	ScavTrap p2("MAURICE");

	std::cout >> p1;
	std::cout >> p2;

	p1.attack("Someone");
	p2.attack("Someone");

	p2.guardGate();

	std::cout >> p1;
	std::cout >> p2;
}
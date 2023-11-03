#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main(void)
{
	ClapTrap p1("BOB");
	ScavTrap p2("MAURICE");
	FragTrap p3("DIDIER");
	DiamondTrap p4("BENARD");

	std::cout >> p1;
	std::cout >> p2;
	std::cout >> p3;
	std::cout >> p4;

	p1.attack("Someone");
	p2.attack("Someone");
	p3.attack("Someone");
	p4.attack("Someone");

	p2.guardGate();
	p3.highFivesGuys();
	p4.whoAmI();

	std::cout >> p1;
	std::cout >> p2;
	std::cout >> p3;
}
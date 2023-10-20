#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
	ClapTrap p1("BOB");
	ScavTrap p2("MAURICE");
	FragTrap p3("DIDIER");

	std::cout >> p1;
	std::cout >> p2;
	std::cout >> p3;

	p1.attack("Someone");
	p2.attack("Someone");
	p3.attack("Someone");

	p2.guardGate();
	p3.highFivesGuys();

	std::cout >> p1;
	std::cout >> p2;
	std::cout >> p3;
}
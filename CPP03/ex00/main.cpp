#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap p1("BOB");
	ClapTrap p2("MAURICE");

	p1.set_ad(3);
	p2.set_ad(1);

	std::cout >> p1;
	std::cout >> p2;

	p1.attack(p2.get_name());
	p2.takeDamage(p1.get_ad());
	p1.attack(p2.get_name());
	p2.takeDamage(p1.get_ad());
	p1.attack(p2.get_name());
	p2.takeDamage(p1.get_ad());
	p1.attack(p2.get_name());
	p2.takeDamage(p1.get_ad());
	p1.attack(p2.get_name());
	p2.takeDamage(p1.get_ad());

	std::cout >> p1;
	std::cout >> p2;

	p1.beRepaired(1);
	for (int i = 0; i <= 5; i++)
		p1.attack(p2.get_name());
	for (int i = 0; i < 10; i++)
		p2.beRepaired(1);

	std::cout >> p2;

	p2.beRepaired(1);
	std::cout >> p2;
}
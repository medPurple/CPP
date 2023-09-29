#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->_name = name;
	this->weapon = weapon;

	std::cout << this->_name << " join the battle with a " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA(){
	std::cout << this->_name << " die in the battle" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with " << this->weapon.getType() << std::endl;
}
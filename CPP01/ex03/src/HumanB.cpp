#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_has_weapon = false;
	std::cout << this->_name << " join the battle" << std::endl;
}

HumanB::~HumanB()
{
	std::cout <<  this->_name << " die in the battle" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_has_weapon = true;
	this->weapon = &weapon;
	std::cout << this->_name << " find something in the battle .... a " << this->weapon->getType() << std::endl; 
}

void HumanB::attack()
{
	if (this->_has_weapon)
		std::cout << this->_name << " attacks with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their fist" << std::endl;


}
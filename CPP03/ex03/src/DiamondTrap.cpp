#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    ClapTrap::_name = "Unknow";
    this->set_name("Unknow");
	this->set_ad(30);
	this->set_hp(100);
	this->set_energy(100);
	std::cout << "[Default DT]\t Constructor called" << std::endl;
}
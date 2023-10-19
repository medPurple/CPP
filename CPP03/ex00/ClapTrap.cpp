#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str):_name(str),
									_hpoint(10),
									_energy(10),
									_ad(0){}

ClapTrap::ClapTrap(const ClapTrap& copy){*this = copy;}

ClapTrap::~ClapTrap(){}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs){(void)rhs; return(*this);}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy > 0 && this->_hpoint > 0)
	{
		std::cout << "ClapTrap " << this->_name << "attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "ClapTrap " << this->_name << "can't do anything" << std::endl;
}
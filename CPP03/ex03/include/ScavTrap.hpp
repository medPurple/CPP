#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: virtual public ClapTrap
{
	public :
				ScavTrap();
				ScavTrap(std::string name);
				ScavTrap(const ScavTrap& rhs);
				~ScavTrap();

				ScavTrap&	operator=(const ScavTrap& rhs);

				void attack(const std::string& target);
				void guardGate(void);

	protected :
				static const int default_hp = 100;
				static const int default_e = 50;
				static const int default_ad = 20;

};

std::ostream& operator>>(std::ostream& o, const ScavTrap& rhs);
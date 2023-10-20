#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap
{
	public :
				ScavTrap();
				ScavTrap(std::string name);
				ScavTrap(const ScavTrap& rhs);
				~ScavTrap();

				ScavTrap&	operator=(const ScavTrap& rhs);

				void attack(const std::string& target);
				void guardGate(void);

};

std::ostream& operator>>(std::ostream& o, const ScavTrap& rhs);
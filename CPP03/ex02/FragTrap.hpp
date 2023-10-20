#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: public ClapTrap
{
	public :
				FragTrap();
				FragTrap(std::string name);
				FragTrap(const FragTrap& rhs);
				~FragTrap();

				FragTrap&	operator=(const FragTrap& rhs);

				void highFivesGuys(void);

};

std::ostream& operator>>(std::ostream& o, const FragTrap& rhs);
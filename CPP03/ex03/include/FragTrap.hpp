#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap
{
	public :
				FragTrap();
				FragTrap(std::string name);
				FragTrap(const FragTrap& rhs);
				~FragTrap();

				FragTrap&	operator=(const FragTrap& rhs);

				void highFivesGuys(void);

	protected :
				static const int default_hp = 100;
				static const int default_e = 100;
				static const int default_ad = 30;

};

std::ostream& operator>>(std::ostream& o, const FragTrap& rhs);
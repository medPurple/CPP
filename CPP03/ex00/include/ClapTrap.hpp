#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	private	:
				std::string _name;
				int _hpoint;
				int _energy;
				int _ad;
	
	public	:
				ClapTrap(void);
				ClapTrap(std::string str);
				ClapTrap(const ClapTrap& copy);
				~ClapTrap();

				ClapTrap&	operator=(const ClapTrap& rhs);

				void 		set_ad(unsigned int ad);
				std::string get_name(void) const;
				int			get_hp(void) const;
				int			get_energy(void) const;
				int			get_ad(void) const;

				void attack(const std::string& target);
				void takeDamage(unsigned int amount);
				void beRepaired(unsigned int amount);
};

std::ostream& operator>>(std::ostream& o, const ClapTrap& rhs);
#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	protected	:
				std::string _name;
				unsigned int _hpoint;
				unsigned int _energy;
				unsigned int _ad;
	
	public	:
				ClapTrap(void);
				ClapTrap(std::string str);
				ClapTrap(const ClapTrap& copy);
				virtual ~ClapTrap();

				ClapTrap&	operator=(const ClapTrap& rhs);

				virtual std::string get_name(void) const;
				virtual unsigned int			get_hp(void) const;
				virtual unsigned int			get_energy(void) const;
				virtual unsigned int			get_ad(void) const;

				void attack(const std::string& target);
				void takeDamage(unsigned int amount);
				void beRepaired(unsigned int amount);
};

std::ostream& operator>>(std::ostream& o, const ClapTrap& rhs);
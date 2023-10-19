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
				ClapTrap(std::string str);
				ClapTrap(const ClapTrap& copy);
				~ClapTrap();

				ClapTrap&	operator=(const ClapTrap& rhs);

				void attack(const std::string& target);
				void takeDamage(unsigned int amount);
				void beRepaired(unsigned int amount);
};
#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{

	private :
				std::string _name;
				Weapon		*weapon;
				bool		_has_weapon;
	
	public	:
				HumanB(std::string name);
				~HumanB(void);
				void attack(void);
				void setWeapon(Weapon &weapon);
};
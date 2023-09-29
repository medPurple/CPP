#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA{

	private :
				std::string _name;
				Weapon		&weapon;
	
	public	:
				HumanA(std::string name, Weapon &weapon);
				~HumanA(void);
				void attack(void);
};
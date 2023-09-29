#pragma once

#include <string>
#include <iostream>

class Weapon{

	private	:
				std::string _type;
	public	:
				Weapon(const std::string &str);
				~Weapon(void);

				std::string getType()const;
				void setType(const std::string &weapon);
};
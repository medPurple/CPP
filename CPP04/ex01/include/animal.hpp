#pragma once

#include <iostream>

class Animal
{
	protected :
				std::string _type;
	
	public 	:
				Animal();
				Animal(const Animal& rhs);
				Animal &operator=(const Animal &rhs);
				virtual ~Animal();

				void set_type(std::string type);
				std::string get_type() const;

				virtual void makeSound(void) const;
};
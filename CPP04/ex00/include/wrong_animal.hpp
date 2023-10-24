#pragma once

#include <iostream>

class Wrong_Animal
{
	protected :
				std::string _type;
	
	public 	:
				Wrong_Animal();
				Wrong_Animal(const Wrong_Animal& rhs);
				Wrong_Animal &operator=(const Wrong_Animal &rhs);
				virtual ~Wrong_Animal();

				void set_type(std::string type);
				std::string get_type() const;

				virtual void makeSound(void) const;
};
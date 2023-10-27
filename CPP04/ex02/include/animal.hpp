#pragma once

#include <iostream>

class AAnimal
{
	protected :
				std::string _type;
				AAnimal();
				
	public 	:
				AAnimal(const AAnimal& rhs);
				AAnimal &operator=(const AAnimal &rhs);
				virtual ~AAnimal();

				void set_type(std::string type);
				std::string get_type() const;

				virtual void makeSound(void) const = 0;
};
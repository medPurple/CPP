#pragma once

#include <iostream>
#include "animal.hpp"

class Dog : public Animal
{
	public 	:
				Dog();
				Dog(const Dog& rhs);
				Dog &operator=(const Dog &rhs);
				~Dog();

				void makeSound(void) const;
};
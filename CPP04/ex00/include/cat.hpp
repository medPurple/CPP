#pragma once

#include <iostream>
#include "animal.hpp"

class Cat : public Animal
{
	public 	:
				Cat();
				Cat(const Cat& rhs);
				Cat &operator=(const Cat &rhs);
				~Cat();

				void makeSound(void) const;
};
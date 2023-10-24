#pragma once

#include <iostream>
#include "wrong_animal.hpp"

class Wrong_Cat : public Wrong_Animal
{
	public 	:
				Wrong_Cat();
				Wrong_Cat(const Wrong_Cat& rhs);
				Wrong_Cat &operator=(const Wrong_Cat &rhs);
				~Wrong_Cat();

				void makeSound(void) const;
};
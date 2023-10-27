#pragma once

#include <iostream>
#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
	private :
				Brain *_brain;
	public 	:
				Dog();
				Dog(const Dog& rhs);
				Dog &operator=(const Dog &rhs);
				virtual ~Dog();

				void makeSound(void) const;
				void fill_brain(void);
				std::string show_brain();
};
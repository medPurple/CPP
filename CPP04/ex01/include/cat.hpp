#pragma once

#include <iostream>
#include "animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
	private :
				Brain *_brain;
	public 	:
				Cat();
				Cat(const Cat& rhs);
				Cat &operator=(const Cat &rhs);
				virtual ~Cat();

				void makeSound(void) const;
				void fill_brain(void);
				std::string show_brain();

};
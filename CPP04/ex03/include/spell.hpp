#pragma once

#include <iostream>
#include "amateria.hpp"

class Ice : public AMateria
{
	public	:
			Ice();
			Ice(const Ice& rhs);
			virtual ~Ice();

			Ice& operator=(const Ice& rhs);

			virtual Ice* clone() const;
};

class Cure : public AMateria
{
	public	:
			Cure();
			Cure(const Cure& rhs);
			virtual ~Cure();

			Cure& operator=(const Cure& rhs);

			virtual Cure* clone() const;
};
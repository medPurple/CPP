#pragma once

#include <iostream>
#include "character.hpp"

class AMateria
{
	protected:
				std::string _type;

	public:
	
				AMateria(std::string const & type);
				AMateria(const AMateria& rhs);
				AMateria &operator=(const AMateria &rhs);
				~AMateria();

				std::string const & getType() const;
				virtual AMateria* clone() const = 0;
				virtual void use(ICharacter& target);
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const& type) = 0;
};

class MateriaSource : public IMateriaSource
{
	protected	:
				AMateria *_materia[4];
	
	public		:
				MateriaSource();
				MateriaSource(const MateriaSource& rhs);
				virtual ~MateriaSource();

				MateriaSource& operator=(const MateriaSource& rhs);

				void learnNateria(AMateria* rhs);
				AMateria* createMateria(std::string const& type) 
};
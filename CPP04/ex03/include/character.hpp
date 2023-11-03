#pragma once

#include <iostream>
#include "amateria.hpp"


class AMateria;


class ICharacter
{
	public:
			virtual ~ICharacter() {}
			virtual std::string const & getName() const = 0;
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
			virtual	AMateria *stuff_adress(int idx) = 0;

};


class Character : public ICharacter
{
	protected	:
					std::string _name;
					AMateria *_inventory[4];
					Character();

	public 		:	
					Character(std::string name);
					Character(const Character& rhs);
					~Character();

					Character& operator=(const Character& rhs);

					std::string const & getName() const;
					void equip(AMateria* m);
					void unequip(int idx);
					void use(int idx, ICharacter& target);
					AMateria *stuff_adress(int idx);
};
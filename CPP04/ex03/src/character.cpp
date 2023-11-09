#include "character.hpp"

Character::Character(std::string name){
	std::cout << "[Character] Default constructor called for "<< name << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;}

Character::Character(const Character& rhs){
	std::cout << "[Character] Copy constructor called for "<< rhs._name << std::endl;
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = rhs._inventory[i];}

Character::~Character(){
	std::cout << "[Character] Default destructor called for "<< this->_name << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	}

Character& Character::operator=(const Character& rhs){
	std::cout << "[Character] Copy assignement called for "<< rhs._name << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i];
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}



std::string const& Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	if (m == NULL)
	{
		std::cout << "Can't equip an unexisting thing" << std::endl; 
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			std::cout << this->_name << " now has " << m->getType() << " in his inventory" << std::endl; 
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << this->_name << " has a full bag and can't keep " << m->getType() << " in his inventory" << std::endl;
	return;
}
void Character::unequip(int idx){
	if (this->_inventory[idx])
		std::cout << this->getName() << " is dropping something" << std::endl;	
	else
		std::cout << this->getName() << " isn't dropping anything" << std::endl;	
	this->_inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target){
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Trying to use an empty slot" << std::endl;
}

AMateria *Character::stuff_adress(int idx){
	if (_inventory[idx])
		return _inventory[idx];
	return (NULL);
}

void Character::showInv(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
			std::cout << "\t[EMPTY]\t";
		else
			std::cout << "\t[" << _inventory[i]->getType() << "]\t";
	}
	std::cout << std::endl;
}

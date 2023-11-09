#include "amateria.hpp"

MateriaSource::MateriaSource(){
	std::cout << "[MateriaSource] Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs){
	std::cout << "[MateriaSource] Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		if (rhs._materia[i])
			this->_materia[i] = rhs._materia[i];
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource(){
	std::cout << "[MateriaSource] Default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _materia[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs){
	std::cout << "[MateriaSource] Copy assignement called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			if (rhs._materia[i])
				this->_materia[i] = rhs._materia[i];
			else
				this->_materia[i] = NULL;
		}
	}
	return *this;
}

void		MateriaSource::learnMateria(AMateria* m){
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			return;
		}
	}
	std::cerr << "Can't save a new materia." << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type){

	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	std::cerr << "This type does not exist or not create yet" << std::endl;
	return NULL;
}

void MateriaSource::showMateria(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
			std::cout << "\t[EMPTY]\t";
		else
			std::cout << "\t[" << _materia[i]->getType() << "]\t";
	}
	std::cout << std::endl;
}

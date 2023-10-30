#include "amateria.hpp"

AMateria::AMateria(std::string const& type){this->_type = type;std::cout << "[AMateria] Default constructor called" << std::endl;}

AMateria::AMateria(const AMateria& rhs){std::cout << "[AMateria] Copy constructor called" << std::endl; *this = rhs;}

AMateria::~AMateria(){std::cout << "[AMateria] Default destructor called" << std::endl;}

AMateria& AMateria::operator=(const AMateria& rhs){std::cout << "[AMateria] Copy assignement called" << std::endl; this->_type = rhs._type; return *this;}

std::string const& AMateria::getType()const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {

	int i;

	std::string str[2] = {"ice", "cure"};
	for (int i = 0; i < 2; i++)
		if (this->_type == str[i])
			break;
	switch (i)
	{
	case 0:
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
		break;
	case 1:
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
		break;
	default:
		std::cout << "* use a strange magic on " << target.getName() << " *" << std::endl;
	}	
}
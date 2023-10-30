#include "spell.hpp"


Cure::Cure() : AMateria("Cure"){std::cout << "[Cure] Default constructor called" << std::endl;}

Cure::Cure(const Cure& rhs) : AMateria(rhs.getType()){std::cout << "[Cure] Copy constructor called" << std::endl; *this = rhs;}

Cure::~Cure(){std::cout << "[Cure] Default destructor called" << std::endl;}

Cure& Cure::operator=(const Cure& rhs){this->_type = rhs._type; std::cout << "[Cure] Copy assignement called" << std::endl; return *this;}

Cure* Cure::clone() const{ return new Cure(*this); std::cout << "[Cure] Clonning....." << std::endl;}
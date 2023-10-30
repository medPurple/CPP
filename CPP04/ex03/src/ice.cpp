#include "spell.hpp"


Ice::Ice() : AMateria("cure"){std::cout << "[Ice] Default constructor called" << std::endl;}

Ice::Ice(const Ice& rhs) : AMateria(rhs.getType()){std::cout << "[Ice] Copy constructor called" << std::endl; *this = rhs;}

Ice::~Ice(){std::cout << "[Ice] Default destructor called" << std::endl;}

Ice& Ice::operator=(const Ice& rhs){this->_type = rhs._type; std::cout << "[Ice] Copy assignement called" << std::endl; return *this;}

Ice* Ice::clone() const{ return new Ice(*this); std::cout << "[Ice] Clonning....." << std::endl;}
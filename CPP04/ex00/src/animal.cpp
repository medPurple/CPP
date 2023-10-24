#include "animal.hpp"

// Coplien

Animal::Animal(){std::cout << "[Animal] Default constructor called" << std::endl; this->_type = "???";}

Animal::Animal(const Animal& rhs){std::cout << "[Animal] Copy constructor called" << std::endl; *this = rhs;}

Animal::~Animal(){std::cout << "[Animal] Default destructor called" << std::endl;}

Animal& Animal::operator=(const Animal& rhs){this->_type = rhs._type; std::cout << "[Animal] Copy assignement called" << std::endl; return *this;}

// getter | setter

void Animal::set_type(std::string type){this->_type = type;}

std::string Animal::get_type(void) const {return this->_type;}


// Fonction

void Animal::makeSound() const { std::cout << "Strange sound " << std::endl;}
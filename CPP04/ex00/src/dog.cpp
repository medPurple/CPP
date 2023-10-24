#include "dog.hpp"
#include "animal.hpp"

// Coplien

Dog::Dog() : Animal(){std::cout << "[Dog] Default constructor called" << std::endl; this->set_type("Dog");}

Dog::Dog(const Dog& rhs) : Animal(rhs){std::cout << "[Dog] Copy constructor called" << std::endl; *this = rhs;}

Dog::~Dog(){std::cout << "[Dog] Default destructor called" << std::endl;}

Dog& Dog::operator=(const Dog& rhs){this->_type = rhs._type; std::cout << "[Dog] Copy assignement called" << std::endl; return *this;}

// Fonction

void Dog::makeSound() const { std::cout << "Ouaf" << std::endl;}
#include "wrong_animal.hpp"

// Coplien

Wrong_Animal::Wrong_Animal(){std::cout << "[Wrong_Animal] Default constructor called" << std::endl; this->_type = "???";}

Wrong_Animal::Wrong_Animal(const Wrong_Animal& rhs){std::cout << "[Wrong_Animal] Copy constructor called" << std::endl; *this = rhs;}

Wrong_Animal::~Wrong_Animal(){std::cout << "[Wrong_Animal] Default destructor called" << std::endl;}

Wrong_Animal& Wrong_Animal::operator=(const Wrong_Animal& rhs){this->_type = rhs._type; std::cout << "[Wrong_Animal] Copy assignement called" << std::endl; return *this;}

// getter | setter

void Wrong_Animal::set_type(std::string type){this->_type = type;}

std::string Wrong_Animal::get_type(void) const {return this->_type;}


// Fonction

void Wrong_Animal::makeSound() const { std::cout << "Weird sound " << std::endl;}
#include "wrong_cat.hpp"
#include "wrong_animal.hpp"

// Coplien

Wrong_Cat::Wrong_Cat() : Wrong_Animal(){std::cout << "[Wrong_Cat] Default constructor called" << std::endl; this->set_type("Wrong_Cat");}

Wrong_Cat::Wrong_Cat(const Wrong_Cat& rhs) : Wrong_Animal(rhs){std::cout << "[Wrong_Cat] Copy constructor called" << std::endl; *this = rhs;}

Wrong_Cat::~Wrong_Cat(){std::cout << "[Wrong_Cat] Default destructor called" << std::endl;}

Wrong_Cat& Wrong_Cat::operator=(const Wrong_Cat& rhs){this->_type = rhs._type; std::cout << "[Wrong_Cat] Copy assignement called" << std::endl; return *this;}

// Fonction

void Wrong_Cat::makeSound() const { std::cout << "GRAAAAOUUUUUU" << std::endl;}
#include "cat.hpp"
#include "animal.hpp"

// Coplien

Cat::Cat() : Animal(){std::cout << "[Cat] Default constructor called" << std::endl; this->set_type("Cat");}

Cat::Cat(const Cat& rhs) : Animal(rhs){std::cout << "[Cat] Copy constructor called" << std::endl; *this = rhs;}

Cat::~Cat(){std::cout << "[Cat] Default destructor called" << std::endl;}

Cat& Cat::operator=(const Cat& rhs){this->_type = rhs._type; std::cout << "[Cat] Copy assignement called" << std::endl; return *this;}

// Fonction

void Cat::makeSound() const { std::cout << "Miaou" << std::endl;}
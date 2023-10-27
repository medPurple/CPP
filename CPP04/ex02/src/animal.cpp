#include "animal.hpp"

// Coplien

AAnimal::AAnimal(){std::cout << "[Animal] Default constructor called" << std::endl; this->_type = "???";}

AAnimal::AAnimal(const AAnimal& rhs){std::cout << "[Animal] Copy constructor called" << std::endl; *this = rhs;}

AAnimal::~AAnimal(){std::cout << "[Animal] Default destructor called" << std::endl;}

AAnimal& AAnimal::operator=(const AAnimal& rhs){this->_type = rhs._type; std::cout << "[Animal] Copy assignement called" << std::endl; return *this;}

// getter | setter

void AAnimal::set_type(std::string type){this->_type = type;}

std::string AAnimal::get_type(void) const {return this->_type;}


// Fonction

void AAnimal::makeSound() const { std::cout << "Strange sound " << std::endl;}
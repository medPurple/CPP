#include "dog.hpp"
#include "animal.hpp"

// Coplien

Dog::Dog(){

	this->_brain = new Brain();
	this->set_type("Dog");
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : AAnimal(rhs){std::cout << "[Dog] Copy constructor called" << std::endl; *this = rhs;}

Dog::~Dog(){delete _brain; std::cout << "[Dog] Default destructor called" << std::endl;}

Dog& Dog::operator=(const Dog& rhs){
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "[Dog] Copy assignement called" << std::endl;
	return *this;}

// Fonction

void Dog::makeSound() const { std::cout << "Ouaf" << std::endl;}
void Dog::fill_brain()
{
	if (_brain) {_brain->fill_idea();}
	else {std::cout << "No brain" << std::endl;}
}

std::string Dog::show_brain()
{
	if (_brain) {return (_brain->show_idea());}
	else {return ("No brain");}
}
#include "cat.hpp"
#include "animal.hpp"

// Coplien

Cat::Cat() : Animal(){
	
	this->_brain = new Brain();
	this->set_type("Cat");
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs){std::cout << "[Cat] Copy constructor called" << std::endl; *this = rhs;}

Cat::~Cat(){delete _brain; std::cout << "[Cat] Default destructor called" << std::endl;}

Cat& Cat::operator=(const Cat& rhs){
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "[Cat] Copy assignement called" << std::endl;
	return *this;}

// Fonction

void Cat::makeSound() const { std::cout << "Miaou" << std::endl;}

void Cat::fill_brain()
{
	if (_brain) {_brain->fill_idea();}
	else {std::cout << "No brain" << std::endl;}
}

std::string Cat::show_brain()
{
	if (_brain) {return (_brain->show_idea());}
	else {return ("No brain");}
}
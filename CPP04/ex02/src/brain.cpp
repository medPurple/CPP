#include "brain.hpp"

// Coplien

Brain::Brain(){std::cout << "[Brain] Default constructor called" << std::endl;}

Brain::Brain(const Brain& rhs){std::cout << "[Brain] Copy constructor called" << std::endl; *this = rhs;}

Brain::~Brain(){std::cout << "[Brain] Default destructor called" << std::endl;}

Brain& Brain::operator=(const Brain& rhs){
	for (int i = 0; i < 100; i++) 
		this->_ideas[i] = rhs._ideas[i];
	std::cout << "[Brain] Copy assignement called" << std::endl; return *this;
}

// Fonctions

void Brain::fill_idea()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "test";
}

std::string Brain::show_idea()
{
	return (this->_ideas[1]);
}
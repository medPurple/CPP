#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "Unknow";
	this->_ad = 20;
	this->_hpoint = 100;
	this->_energy = 50;
	std::cout << "[Default ST]\t Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string str)
{
	this->_name = str;
	this->_ad = 20;
	this->_hpoint = 100;
	this->_energy = 50;
	std::cout << "[Param ST]\t Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs){
	this->_ad = rhs._ad;
	this->_hpoint = rhs._hpoint;
	this->_energy = rhs._energy;
	this->_name = rhs._name;
	 std::cout << "[Copy ST]\t Constructor called" << std::endl;}

ScavTrap::~ScavTrap(){std::cout << "[Default ST]\t Destructor called" << std::endl;}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs){
	if (this != &rhs)
	{
		this->_ad = rhs._ad;
		this->_hpoint = rhs._hpoint;
		this->_energy = rhs._energy;
		this->_name = rhs._name;
	}
	return (*this);
}


std::ostream& operator>>(std::ostream& o, const ScavTrap& rhs)
{
	o	<< "--------------ScavTrap------------\n"
		<< "[Name]\t" << rhs.get_name() << "\n"
		<< "[HP]\t" << rhs.get_hp() << "\n"
		<< "[AD]\t" << rhs.get_ad() << "\n"
		<< "[E]\t"	<< rhs.get_energy() << "\n"
		<< "----------------------------------\n" << std::endl;
	return o;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy > 0 && this->_hpoint > 0)
	{
		std::cout	<< "ScavTrap " 
					<< this->_name
					<< " attacks "
					<< target 
					<< ", causing " 
					<< this->_ad
					<< " points of damage!"
					<< std::endl;
		this->_energy -= 1;
	}
	else
		std::cout	<< "ScavTrap "
					<< this->_name
					<< " can't do anything" 
					<< std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is in guard mode" << std::endl;
}
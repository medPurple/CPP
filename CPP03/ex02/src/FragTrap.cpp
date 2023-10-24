#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "Unknow";
	this->_ad = 30;
	this->_hpoint = 100;
	this->_energy = 100;
	std::cout << "[Default FT]\t Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string str)
{
	this->_name = str;
	this->_ad = 30;
	this->_hpoint = 100;
	this->_energy = 100;
	std::cout << "[Param FT]\t Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs){
		this->_ad = rhs._ad;
		this->_hpoint = rhs._hpoint;
		this->_energy = rhs._energy;
		this->_name = rhs._name; 
		std::cout << "[Copy FT]\t Constructor called" << std::endl;}

FragTrap::~FragTrap(){std::cout << "[Default FT]\t Destructor called" << std::endl;}

FragTrap& FragTrap::operator=(const FragTrap& rhs){
	if (this != &rhs)
	{
		this->_ad = rhs._ad;
		this->_hpoint = rhs._hpoint;
		this->_energy = rhs._energy;
		this->_name = rhs._name;
	}
	return (*this);
}

std::ostream& operator>>(std::ostream& o, const FragTrap& rhs)
{
	o	<< "--------------FragTrap------------\n"
		<< "[Name]\t" << rhs.get_name() << "\n"
		<< "[HP]\t" << rhs.get_hp() << "\n"
		<< "[AD]\t" << rhs.get_ad() << "\n"
		<< "[E]\t"	<< rhs.get_energy() << "\n"
		<< "----------------------------------\n" << std::endl;
	return o;
}

void FragTrap::highFivesGuys(void)
{
	std::cout	<< "[" << this->_name << "]"
				<< " Yo mate let's high five !" << std::endl;
}
#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->set_name("Unknow");
	this->set_ad(20);
	this->set_hp(100);
	this->set_energy(50);
	std::cout << "[Default ST]\t Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string str)
{
	this->set_name(str);
	this->set_ad(20);
	this->set_hp(100);
	this->set_energy(50);
	std::cout << "[Param ST]\t Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy){*this = copy; std::cout << "[Copy ST]\t Constructor called" << std::endl;}

ScavTrap::~ScavTrap(){std::cout << "[Default ST]\t Destructor called" << std::endl;}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs){*this = rhs; return *this;}


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
	if (this->get_energy() > 0 && this->get_hp() > 0)
	{
		std::cout	<< "ScavTrap " 
					<< this->get_name() 
					<< " attacks "
					<< target 
					<< ", causing " 
					<< this->get_ad() 
					<< " points of damage!"
					<< std::endl;
		this->set_energy(this->get_energy() - 1);
	}
	else
		std::cout	<< "ScavTrap "
					<< this->get_name()
					<< " can't do anything" 
					<< std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->get_name() << " is in guard mode" << std::endl;
}
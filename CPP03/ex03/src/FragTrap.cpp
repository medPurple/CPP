#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->set_name("Unknow");
	this->set_ad(30);
	this->set_hp(100);
	this->set_energy(100);
	std::cout << "[Default FT]\t Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string str)
{
	this->set_name(str);
	this->set_ad(30);
	this->set_hp(100);
	this->set_energy(100);
	std::cout << "[Param FT]\t Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy){*this = copy; std::cout << "[Copy FT]\t Constructor called" << std::endl;}

FragTrap::~FragTrap(){std::cout << "[Default FT]\t Destructor called" << std::endl;}

FragTrap& FragTrap::operator=(const FragTrap& rhs){*this = rhs; return *this;}


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
	std::cout	<< "[" << this->get_name() << "]"
				<< " Yo mate let's high five !" << std::endl;
}
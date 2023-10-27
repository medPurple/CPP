#include "../include/DiamondTrap.hpp"


// Constructor 

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
    ClapTrap::_name = "Unknow_clap_name";
    this->_name = "Unknow";
    this->_ad = FragTrap::default_ad;
    this->_energy = ScavTrap::default_e;
    this->_hpoint = FragTrap::default_hp;
    std::cout << "[Default DT]\t Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->ClapTrap::_name = name + "_clap_name";
    this->_name = name;
    this->_ad = FragTrap::default_ad;
    this->_energy = ScavTrap::default_e;
    this->_hpoint = FragTrap::default_hp;
    std::cout << "[Param DT]\t Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs){*this = rhs; std::cout << "[Copy DT]\t Constructor called" << std::endl;}


//  Destructor

DiamondTrap::~DiamondTrap(){std::cout << "[Default DT]\t Destructor called" << std::endl;}


// Operator

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs){
	if (this != &rhs)
	{
		this->_ad = rhs._ad;
		this->_hpoint = rhs._hpoint;
		this->_energy = rhs._energy;
		this->_name = rhs._name;
		ClapTrap::_name = (this->_name + "_clap_name");
	}
	return (*this);
}

std::ostream& operator>>(std::ostream& o, const DiamondTrap& rhs)
{
	o	<< "--------------FragTrap------------\n"
		<< "[Name]\t" << rhs.get_name() << "\n"
		<< "[HP]\t" << rhs.get_hp() << "- > FT \n"
		<< "[AD]\t" << rhs.get_ad() << "- > FT\n"
		<< "[E]\t"	<< rhs.get_energy() << "- > ST\n"
		<< "----------------------------------\n" << std::endl;
	return o;
}

// Fonctions

std::string DiamondTrap::get_name(void) const
{
	return (this->_name);
}


void DiamondTrap::whoAmI()
{
    std::cout << "Hi! I'm " << this->_name << ", also known as: Claptrap " << ClapTrap::_name << std::endl;
}


void        DiamondTrap::attack(const std::string& target)
{
    if (this->_energy > 0)
    {
        ScavTrap::attack(target);
        this->_energy--;
    }
    else
        std::cout << "DiamondTrap (" << _name << ") is out of energy!" << std::endl;
}
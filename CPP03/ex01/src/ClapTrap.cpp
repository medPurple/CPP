#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void):	_name("Unknow"),
						_hpoint(10),
						_energy(10),
						_ad(0){std::cout << "[Default CT]\t Constructor called" << std::endl;}

ClapTrap::ClapTrap(std::string str):	_name(str),
										_hpoint(10),
										_energy(10),
										_ad(0){std::cout << "[Param CT]\t Constructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap& rhs){
	this->_ad = rhs._ad;
	this->_hpoint = rhs._hpoint;
	this->_energy = rhs._energy;
	this->_name = rhs._name;
	std::cout << "[Copy CT]\t Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){std::cout << "[Default CT]\t Destructor called" << std::endl;}

// Operator

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs){
	
	if (this != &rhs)
	{
		this->_ad = rhs._ad;
		this->_hpoint = rhs._hpoint;
		this->_energy = rhs._energy;
		this->_name = rhs._name;
	}
	return (*this);
}

std::ostream& operator>>(std::ostream& o, const ClapTrap& rhs)
{
	o	<< "---------------ClapTrap-----------\n"
		<< "[Name]\t" << rhs.get_name() << "\n"
		<< "[HP]\t" << rhs.get_hp() << "\n"
		<< "[AD]\t" << rhs.get_ad() << "\n"
		<< "[E]\t"	<< rhs.get_energy() << "\n"
		<< "----------------------------------\n" << std::endl;
	return o;
}

// Setter

void 			ClapTrap::set_ad(unsigned int ad){this->_ad = ad;}
void 			ClapTrap::set_energy(unsigned int e){this->_energy = e;}
void 			ClapTrap::set_hp(unsigned int hp){this->_hpoint = hp;}
void			ClapTrap::set_name(std::string str){this->_name = str;}


// Getter

std::string 	ClapTrap::get_name(void) const{return this->_name;}
int 			ClapTrap::get_ad(void) const{return this->_ad;}
int 			ClapTrap::get_energy(void) const{return this->_energy;}
int 			ClapTrap::get_hp(void) const{return this->_hpoint;}


// Fonction

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy > 0 && this->_hpoint > 0)
	{
		std::cout	<< "ClapTrap " 
					<< this->_name 
					<< " attacks "
					<< target 
					<< ", causing " 
					<< this->_ad 
					<< " points of damage!"
					<< std::endl;
		this->_energy--;
	}
	else
		std::cout	<< "ClapTrap "
					<< this->_name 
					<< " can't do anything" 
					<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hpoint > 0)
	{
		this->_hpoint = this->_hpoint - amount;
		std::cout	<< "ClapTrap "
					<< this->_name
					<< " took "
					<< amount
					<< " damage"
					<< std::endl;
		if (this->_hpoint == 0)
			std::cout << this->_name << " is dead" << std::endl;

	}
	else
		std::cout	<< "Someone hit a dead man (" << this->_name << ")" 
					<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hpoint < 10 && this->_energy > 0)
	{
		this->_hpoint = this->_hpoint + amount;
		this->_energy--;
		std::cout	<< "ClapTrap "
					<< this->_name
					<< " gain "
					<< amount
					<< " HP"
					<< std::endl;
	}
	else if (this->_hpoint < 10 && this->_energy == 0)
	{
		std::cout	<< "ClapTrap "
					<< this->_name
					<< " is too tied to rest" << std::endl;
	}
	else
	{
		std::cout	<< "ClapTrap "
					<< this->_name
					<< " is in shape" << std::endl;
	}
}
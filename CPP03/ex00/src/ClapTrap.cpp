#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void):	_name("Unknow"),
						_hpoint(10),
						_energy(10),
						_ad(0){std::cout << "[Default]\t Constructor called" << std::endl;}

ClapTrap::ClapTrap(std::string str):	_name(str),
										_hpoint(10),
										_energy(10),
										_ad(0){std::cout << "[Param]\t Constructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap& rhs){*this = rhs; std::cout << "[Copy]\t Constructor called" << std::endl;}

ClapTrap::~ClapTrap(){std::cout << "[Default]\t Destructor called" << std::endl;}

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
	o	<< "----------------------------------\n"
		<< "[Name]\t" << rhs.get_name() << "\n"
		<< "[HP]\t" << rhs.get_hp() << "\n"
		<< "[AD]\t" << rhs.get_ad() << "\n"
		<< "[E]\t"	<< rhs.get_energy() << "\n"
		<< "----------------------------------\n" << std::endl;
	return o;
}

// Setter

void 			ClapTrap::set_ad(unsigned int ad){this->_ad = ad;}


// Getter

std::string 			ClapTrap::get_name(void) const{return this->_name;}
unsigned int 			ClapTrap::get_ad(void) const{return this->_ad;}
unsigned int 			ClapTrap::get_energy(void) const{return this->_energy;}
unsigned int 			ClapTrap::get_hp(void) const{return this->_hpoint;}


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
		if (amount <= this->_hpoint)
			this->_hpoint = this->_hpoint - amount;
		else
			this->_hpoint = 0;
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
		if (this->_hpoint + amount <= 10)
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
		else
		{
			this->_hpoint = 10;
			this->_energy--;
			std::cout	<< "ClapTrap "
						<< this->_name
						<< " is now full life."
						<< std::endl;
		}

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
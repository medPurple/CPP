#pragma once

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    
    std::string _name;

public:
    
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &rhs);
    ~DiamondTrap(void);

    DiamondTrap& operator=(const DiamondTrap& obj);

    std::string get_name(void) const;
    void        whoAmI();
    void        attack(const std::string& target);
    
};

std::ostream& operator>>(std::ostream& o, const DiamondTrap& rhs);
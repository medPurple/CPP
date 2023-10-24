#include "../include/Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::complain(std::string str)
{
    int i;

    //void (Harl::*fct[4]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (i = 0; i < 4; i++)
        if (str == level[i])
           break;
    switch (i)
    {
        case 0:
            this->_debug();
        case 1:
            this->_info();
        case 2:
            this->_warning();
        case 3:
        {
            this->_error();
            break;
        }
        default:
            std::cout << "\n[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Harl::_debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\n" << std::endl;
}

void Harl::_info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n" << std::endl;
}

void Harl::_warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::_error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now.\n" << std::endl;
}
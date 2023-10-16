#include "../include/Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::complain(std::string str)
{
    void (Harl::*fct[4]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
        if (str == level[i])
            (this->*fct[i])();
}

void Harl::_debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup \
        burger. I really do !" << std::endl;
}

void Harl::_info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout <<  "cannot believe adding extra bacon costs more money. You didn’t put \
        enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::_warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << " think I deserve to have some extra bacon for free. I’ve been coming \
        for years whereas you started working here since last month." << std::endl;
}

void Harl::_error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
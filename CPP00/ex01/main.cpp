/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:55:24 by purple            #+#    #+#             */
/*   Updated: 2023/10/02 10:15:55 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"
#include "include/Contact.hpp"
static void show_command(void);

int main(void)
{
    PhoneBook   PhoneBook;
    std::string input;
    bool        run = true;

    while(run && std::getline(std::cin, input))
    {
        show_command();
        if (std::cin.eof() == true)
        {
            std::cout << "[Interrut]\n";
            return (0);
        }
        else if (input.compare("ADD") == 0)
            PhoneBook.setInfo();
        else if (input.compare("SEARCH") == 0)
            PhoneBook.getInfo();
        else if (input.compare("EXIT") == 0)
        {
            std::cout << "[Exit]\n";
            run = false;
            break;
        }
        
        input.clear();
    }
    if (run == true)
        std::cout << "[Interrupt]\n";
    return (0);
}


static void show_command(void)
{
    std::cout << "\033[1;35m" << "\tPlease use one of the following command : \n" << "\e[0m";
    std::cout << "\t[" << "\033[1;36m" << "ADD" << "\e[0m" << "]\t";
    std::cout << "\t[" << "\033[1;36m" << "SEARCH" << "\e[0m" << "]\t";
    std::cout << "[" << "\033[1;36m" << "EXIT" << "\e[0m" << "]" << std::endl;
}
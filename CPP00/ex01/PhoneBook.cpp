/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <medpurple@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:22:40 by purple            #+#    #+#             */
/*   Updated: 2023/09/25 21:29:34 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"
#include "include/Contact.hpp"
#include <string>
#include <cctype>

PhoneBook::PhoneBook()
{
    this->_index = 0;
    this->_is_full = false;
    return;   
}

PhoneBook::~PhoneBook()
{
    return;
}

void PhoneBook::setInfo()
{
    std::string input;
    if(this->_is_full != true)
    {
        std::cout << "Contact #" << this->_index + 1 << std::endl;
        if (this->_contact[this->_index].create_contact())
        {
            if (this->_index == 7)
                this->_is_full = true;
            else
                this->_index++;
        }
    }
    else
    {
        std::cout << "Phonebook full, deleting oldest contact\n";
        for (int i = 1; i < 8; i++)
            this->_contact[i - 1] = this->_contact[i];
        std::cout << "Contact #8" << std::endl;
        this->_contact[this->_index].create_contact();
    }
}

void PhoneBook::getInfo()
{
    //int index = 0;
    std::string input;
    int     check = 0;
    bool    run = false;

    if (this->_index == 0)
    {
        std::cout << "Need at least 1 contact to display" << std::endl;
        return;
    }    
    else
    {
        std::cout << "Which contact should be displayed ?\n";
        while (!(std::getline(std::cin, input)) || !(run))
        {
            if (input.length() > 0 )
            {
                for (int i = 0; i < (int)input.length(); i++)
                {
                    if (!(std::isdigit(input[i])) )
                    {
                        std::cout << "Need a number" << std::endl;
                        std::cin.clear();
                    }
                    else
                        check++;
                }
                if((check == (int)input.length()) && ((stoi(input) <= 0 ) || stoi(input) > this->_index))
                {
                    std::cout << "Digit range is [1] to ["<< this->_index << "]" << std::endl;
                    std::cin.clear();
                }
            }
            else if (input.length() == 0)
            {
                if (std::cin.eof() == 0)
                {
                    std::cout << "[Input]" << std::endl;
                    exit(0);
                }
                std::cout << "Need at least 1 number" << std::endl;
                std::cin.clear();
            }
            else
                run = true;
        }
        std::cout << "ok";
    }
}
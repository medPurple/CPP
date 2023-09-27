/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:22:40 by purple            #+#    #+#             */
/*   Updated: 2023/09/27 15:57:01 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"
#include "include/Contact.hpp"
#include <string>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <cstdlib>

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
            {
                this->_is_full = true;
                this->_index++;
            }
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
        this->_contact[this->_index - 1].create_contact();
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
        little_display();
        std::cout << "\n\t-- Which contact should be displayed ? -- \n";
        while (!(std::getline(std::cin, input)) || !(run))
        {
            check = 0;
            if (input.length() > 0 )
            {
                if (input.length() >= 2)
                    std::cout << "Digit range is [1] to ["<< this->_index << "]" << std::endl;
                else
                {
                    for (int i = 0; i < (int)input.length(); i++)
                    {
                        if (!(std::isdigit(input[i])) )
                        {
                            std::cout << "Need a number" << std::endl; 
                            break;
                        }
                        else
                            check++;
                    }
                    if((check == (int)input.length()) && ((atoi(input.c_str()) <= 0) || atoi(input.c_str()) > this->_index))
                        std::cout << "Digit range is [1] to ["<< this->_index << "]" << std::endl;
                    else if (check == (int)input.length() )
                    {
                        run = true;
                        break;
                    }
                }
                std::cin.clear();
            }
            else if (input.length() == 0)
            {
                std::cout << "Need at least 1 number" << std::endl;
                std::cin.clear();
            }
            else
            {
                run = true;
                break;
            }
            input.clear();
        }
        for (int j = 0; j < 5; j++)
        {
            std::cout << this->_contact[0].get_field(j) << "\t:\t";
			std::cout << this->_contact[atoi(input.c_str()) - 1].get_contact(j) << std::endl;
        }
    }
}

void PhoneBook::little_display(void)
{
    
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int k = 0; k < this->_index; k++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << "|";
            if (j == 0)
                std::cout << std::setw(10) << k + 1;
            else
            {
                if (this->_contact[k].get_contact(j - 1).length() > 10)
			        std::cout << this->_contact[k].get_contact(j - 1).substr(0, 9) << ".";
		        else
			        std::cout << std::setw(10) << this->_contact[k].get_contact(j - 1);
            }
        }
        std::cout << "|" << std::endl;    
        std::cout << "|----------|----------|----------|----------|" << std::endl;
    }
}
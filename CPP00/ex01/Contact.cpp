/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <medpurple@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:32:22 by purple            #+#    #+#             */
/*   Updated: 2023/09/25 20:30:33 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"
#include "include/Contact.hpp"

std::string Contact::_field[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
    for (int i = 0; i < 5; i++)
        this->_info[i] = std::string();
    return;
}

Contact::~Contact()
{
    return;
}

bool Contact::create_contact()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter the " << Contact::_field[i] << ":\n";
        while(!(std::getline(std::cin, this->_info[i]) && this->_info[i].length() != 0))
        {
            if (std::cin.eof() == true)
            {
                std::cout << "[Interrupt]" << std::endl;
                return (false);
            }
            else if (this->_info[i].length() == 0)
            {
                std::cout << "Can't create an empty contact\n" << std::endl;
                std::cout << "Enter the " << Contact::_field[i] << ":\n";
            }
        }
    }
    std::cout << "Contact created\n" << std::endl;
    return (true);
}
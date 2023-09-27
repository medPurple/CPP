/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <medpurple@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:47:47 by wmessmer          #+#    #+#             */
/*   Updated: 2023/09/25 18:41:40 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include "../include/PhoneBook.hpp"

class Contact{
    
    private :
                static std::string  _field[5];
                std::string			_info[11];
                
                enum Field{
                    First_name,
                    Last_name,
                    Nickname,
                    PhoneNumber,
                    Deepest_secret,
                };

    public  :
                Contact(void);
                ~Contact(void);
                
                bool create_contact(void);
                void get_contact(int index);
                
};
#endif
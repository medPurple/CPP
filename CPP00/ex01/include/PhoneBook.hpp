/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:43:54 by wmessmer          #+#    #+#             */
/*   Updated: 2023/09/27 13:50:55 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include "Contact.hpp"

class PhoneBook{
    
    private :
                Contact _contact[8];
                int     _index;
                bool    _is_full;
    
    public  :
                PhoneBook(void);
                ~PhoneBook(void);
                
                void setInfo(void);
                void getInfo(void);
                void little_display(void);
};

#endif
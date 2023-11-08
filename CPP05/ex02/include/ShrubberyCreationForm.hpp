#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	public	:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm& rhs);
			~ShrubberyCreationForm();

			std::string getTarget();

	private	:
				std::string _target;

};

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& rhs);
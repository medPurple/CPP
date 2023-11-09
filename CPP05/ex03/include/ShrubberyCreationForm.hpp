#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	public	:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm& rhs);
			~ShrubberyCreationForm();

			void execute(Bureaucrat const& executor) const;
			void draw_tree(std::ofstream &file)const;
			void shrub_exec(void)const;
};
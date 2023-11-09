#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	public	:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(const RobotomyRequestForm& rhs);
			RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);
			~RobotomyRequestForm();

			void execute(Bureaucrat const& executor) const;
			void exec_robot(void) const;

	private	:

};
#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	public	:
			RobotomyRequestForm();
			RobotomyRequestForm(const RobotomyRequestForm& rhs);
			RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);
			~RobotomyRequestForm();

	private	:

};

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& rhs);
#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public		:
			PresidentialPardonForm();
			PresidentialPardonForm(const PresidentialPardonForm& rhs);
			PresidentialPardonForm &operator=(const PresidentialPardonForm& rhs);
			~PresidentialPardonForm();

private	:

};
std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& rhs);
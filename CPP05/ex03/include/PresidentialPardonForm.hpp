#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public		:
				PresidentialPardonForm();
				PresidentialPardonForm(std::string target);
				PresidentialPardonForm(const PresidentialPardonForm& rhs);
				PresidentialPardonForm &operator=(const PresidentialPardonForm& rhs);
				~PresidentialPardonForm();

				void execute(Bureaucrat const& executor) const;

	private	:

};
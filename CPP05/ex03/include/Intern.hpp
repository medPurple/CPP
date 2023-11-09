#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern{
	public		:
// Coplien
			Intern();
			Intern(const Intern& rhs);
			Intern &operator=(const Intern& rhs);
			~Intern();

// Fonction
			AForm *makeForm(std::string form, std::string target);

// Getter / Setter

// Exception
			class FormNotExistException : std::exception {
						public : virtual const char* what() const throw();
					};

	protected	:

	private		:
					AForm *createShrubbery(std::string target);
					AForm *createRobotomy(std::string target);
					AForm *createPresidential(std::string target);

};
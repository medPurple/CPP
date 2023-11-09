#pragma once

#include "AForm.hpp"

#include <iostream>

class AForm;

class Bureaucrat{

	public	:
					Bureaucrat();
					Bureaucrat(std::string name, int grade);
					Bureaucrat(const Bureaucrat &rhs);
					Bureaucrat &operator=(const Bureaucrat &rhs);
					~Bureaucrat();

					std::string	getName() const;
					int			getGrade() const;
					void 		igrade();
					void 		dgrade();
					void		check_grade() const;
					void		signForm(AForm &form);
					void		executeForm(AForm const& form);
	
					class GradeTooHighException : std::exception {
						public : virtual const char* what() const throw();
					};
					class GradeTooLowException : std::exception {
						public : virtual const char* what() const throw();
					};
		
	private	:
					const std::string 	_name;
					int					_grade;

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);


#define Dconst 	"[Bureaucrat] Default constructor called"
#define Pconst 	"[Bureaucrat] Parametric constructor called"
#define Cconst 	"[Bureaucrat] Copy constructor called"
#define Aconst 	"[Bureaucrat] Assignation operator called"
#define Ddest 	"[Bureaucrat] Default deconstructor called"

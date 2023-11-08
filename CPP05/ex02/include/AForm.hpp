#pragma once

#include "Bureaucrat.hpp"

#include <iostream>

class Bureaucrat;

class AForm {

	public	:
		// Coplien
					AForm();
					AForm(std::string name, int gradeS, int gradeE);
					AForm(const AForm &rhs);
					AForm &operator=(const AForm &rhs);
					virtual ~AForm();
		
		// Fonctions
					virtual void beSigned(Bureaucrat ppl) = 0;

		// getter
					std::string getName() const;
					bool		isSigned() const;
					int			getGradeS() const;
					int			getGradeE() const;

		// exeptions
					class GradeTooHighException : std::exception {
						public : virtual const char* what() const throw();
					};
					class GradeTooLowException : std::exception {
						public : virtual const char* what() const throw();
					};
	private	:
				const std::string 	_name;
				bool				_is_signed;
				const int			_require_grade_s;
				const int			_require_grade_e;
};

std::ostream& operator<<(std::ostream& o, const AForm& rhs);


#define FDconst "[AForm] Default constructor called"
#define FPconst "[AForm] Parametric constructor called"
#define FCconst "[AForm] Copy constructor called"
#define FAop 	"[AForm] Assignement operator called"
#define FDdest "[AForm] Default destructor called"

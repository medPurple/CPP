#pragma once

#include "Bureaucrat.hpp"

#include <iostream>

class Form {

	public	:
		// Coplien
					Form();
					Form(std::string name, bool issigned, int gradeS, int gradeE);
					Form(const Form &rhs);
					Form &operator=(const Form &rhs);
					~Form();
		
		// Fonctions
					void beSigned(Bureaucrat ppl);

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

std::ostream& operator<<(std::ostream& o, const Form& rhs);


#define FDconst "[Form] Default constructor called"
#define FPconst "[Form] Parametric constructor called"
#define FCconst "[Form] Copy constructor called"
#define FAop 	"[Form] Assignement operator called"
#define FDdest "[Form] Default destructor called"

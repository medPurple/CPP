#include "PresidentialPardonForm.hpp"




/*----------------- Coplien ------------- */

PresidentialPardonForm::PresidentialPardonForm() : AForm(){

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs){

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){

}


/*---------------- Operator ------------- */

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& rhs){
	o   << std::endl;
	return o; 
}


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */


/*--------------- Exception ------------- */

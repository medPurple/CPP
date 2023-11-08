
#include "RobotomyRequestForm.hpp"


/*----------------- Coplien ------------- */

RobotomyRequestForm::RobotomyRequestForm(){

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs){

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){

}


/*---------------- Operator ------------- */

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& rhs){
	o   << std::endl;
	return o; 
}


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */


/*--------------- Exception ------------- */

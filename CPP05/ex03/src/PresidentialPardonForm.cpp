#include "PresidentialPardonForm.hpp"




/*----------------- Coplien ------------- */

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5, "default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs): AForm(rhs){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
	if (this != &rhs)
		*this = rhs;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){

}


/*---------------- Operator ------------- */


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

void PresidentialPardonForm::execute(Bureaucrat const& executor) const{

	if (this->isSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeE())
		throw GradeTooLowException();
	if (executor.getGrade() < 0)
		throw GradeTooHighException();
	std::cout << this->getTarget() << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}

/*--------------- Exception ------------- */


#include "RobotomyRequestForm.hpp"


/*----------------- Coplien ------------- */

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest", 75, 15, "default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequest", 75, 15, target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs){

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
	if (this != &rhs)
		*this = rhs;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}


/*---------------- Operator ------------- */


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

void RobotomyRequestForm::execute(Bureaucrat const& executor)const{

	if (this->isSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeE())
		throw GradeTooLowException();
	if (executor.getGrade() < 0)
		throw GradeTooHighException();
	exec_robot();
}

void RobotomyRequestForm::exec_robot() const{
	std::cout << "*drilling noises*" << std::endl;
	std::srand(std::time(0));
	int valeur = std::rand()%10 + 1;

	if (valeur <= 5)
		std::cout << this->getTarget() << " has been robotomized ! [" << valeur << "]" << std::endl;
	else
		std::cout << this->getTarget() << " has be..... FAILURE ! [" << valeur << "]" << std::endl;
}
/*--------------- Exception ------------- */

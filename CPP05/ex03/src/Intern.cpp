#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"



/*----------------- Coplien ------------- */

Intern::Intern(){}

Intern::Intern(const Intern& rhs){*this = rhs;}

Intern &Intern::operator=(const Intern& rhs){

	if (this != &rhs)
		*this = rhs;
	return *this;
}

Intern::~Intern(){

}


/*---------------- Operator ------------- */


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

AForm *Intern::makeForm(std::string form, std::string target){
	try{
			int i = 0;
			std::string list[3] = {	"ShrubberyCreationForm"
									"RobotomyRequestForm"
									"PresidentialPardonForm"};
		while (i < 4){ if (list[i] == form) break;}
		switch (i)
		{
			case 0 :
				std::cout << "Intern creates " << list[i] << std::endl;
				return createShrubbery(target);
			case 1 :
				std::cout << "Intern creates " << list[i] << std::endl;
				return createRobotomy(target);
			case 2 :
				std::cout << "Intern creates " << list[i] << std::endl;
				return createPresidential(target);
			default:
				throw FormNotExistException();
		}
	}
	catch (...){std::cout << "Intern can't discover a new form" << std::endl;}
	return NULL;
}

AForm *Intern::createShrubbery(std::string target){
	return new ShrubberyCreationForm(target);
}
AForm *Intern::createRobotomy(std::string target){
	return new RobotomyRequestForm(target);
}
AForm *Intern::createPresidential(std::string target){
	return new PresidentialPardonForm(target);
}
/*--------------- Exception ------------- */

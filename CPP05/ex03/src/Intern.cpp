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

AForm *Intern::makeForm(std::string form, std::string target) const {
	try{
			int i = 0;
			std::string list[3] = {	"ShrubberyCreationForm",
									"RobotomyRequestForm",
									"PresidentialPardonForm"};
		while (i < 3){ if (list[i] == form) break;i++;}
		switch (i)
		{
			case 0 :
				std::cout << "\e[3m\e[32m" << "Intern creates " << list[i] << "\e[0m"  << std::endl;
				return createShrubbery(target);
			case 1 :
				std::cout << "\e[3m\e[32m" << "Intern creates " << list[i] << "\e[0m"  << std::endl;
				return createRobotomy(target);
			case 2 :
				std::cout << "\e[3m\e[32m" << "Intern creates " << list[i] << "\e[0m"  << std::endl;
				return createPresidential(target);
			default:
				throw FormNotExistException();
		}
	}
	catch (...){std::cout << "\e[3m\e[31m" << "Intern can't discover a new form"  << "\e[0m" << std::endl;}
	return NULL;
}

AForm *Intern::createShrubbery(std::string target) const{
	return new ShrubberyCreationForm(target);
}
AForm *Intern::createRobotomy(std::string target) const{
	return new RobotomyRequestForm(target);
}
AForm *Intern::createPresidential(std::string target) const{
	return new PresidentialPardonForm(target);
}
/*--------------- Exception ------------- */

const char* Intern::FormNotExistException::what() const throw() {
	return ("[Form not found]");
}
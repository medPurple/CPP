#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat boss("?", 1);
	Bureaucrat cadre("Sylvie", 70);
	Bureaucrat employe("Maurice", 130);
	Bureaucrat stagiaire("John", 150);

	PresidentialPardonForm 	president("target1");
	RobotomyRequestForm		robot("target2");
	ShrubberyCreationForm	tree("target3");

	std::cout << "\t\t\n---------- Tree -----------\n" << std::endl;

	stagiaire.signForm(tree);
	employe.executeForm(tree);
	employe.signForm(tree);
	employe.executeForm(tree);
	stagiaire.executeForm(tree);

	std::cout << "\t\t\n---------- Robot -----------\n" << std::endl;

	employe.signForm(robot);
	boss.executeForm(robot);
	cadre.signForm(robot);
	boss.executeForm(robot);
	cadre.executeForm(robot);

	std::cout << "\t\t\n---------- Presidential -----------\n" << std::endl;
	
	cadre.signForm(president);
	boss.executeForm(president);
	boss.signForm(president);
	cadre.executeForm(president);
	boss.executeForm(president);

	std::cout << "\n--------------------- End -----------------\n" << std::endl;
	return 0;
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat boss("?", 1);
	Bureaucrat cadre("Sylvie", 70);
	Bureaucrat employe("Maurice", 130);
	Bureaucrat stagiaire("John", 150);


	Intern billy;

	AForm *tree = billy.makeForm("ShrubberyCreationForm", "target1");
	AForm *robot = billy.makeForm("RobotomyRequestForm", "target2");
	AForm *president = billy.makeForm("PresidentialPardonForm", "target2");
	AForm *error = billy.makeForm("error", "target");

	(void)error;
	std::cout << "\t\t\n---------- Tree -----------\n" << std::endl;

	stagiaire.signForm(*tree);
	employe.executeForm(*tree);
	employe.signForm(*tree);
	employe.executeForm(*tree);
	stagiaire.executeForm(*tree);

	std::cout << "\t\t\n---------- Robot -----------\n" << std::endl;

	employe.signForm(*robot);
	boss.executeForm(*robot);
	cadre.signForm(*robot);
	boss.executeForm(*robot);
	cadre.executeForm(*robot);

	std::cout << "\t\t\n---------- Presidential -----------\n" << std::endl;
	
	cadre.signForm(*president);
	boss.executeForm(*president);
	boss.signForm(*president);
	cadre.executeForm(*president);
	boss.executeForm(*president);

	std::cout << "\n--------------------- End -----------------\n" << std::endl;
	return 0;
}
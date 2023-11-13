#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*-----------------------Coplien-----------------------------*/
 
Bureaucrat::Bureaucrat() : _name("unknow"), _grade(151) {};

Bureaucrat::Bureaucrat(std::string name, int grade) :  _name(name), _grade(grade){
	this->check_grade();
	std::cout << Dconst << " for " << this->_name << std::endl;};

Bureaucrat::Bureaucrat(const Bureaucrat &rhs):  _name(rhs.getName()), _grade(rhs.getGrade()){};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
	this->_grade = rhs.getGrade();
	const_cast<std::string&>(this->_name) = rhs.getName();
	return *this;
};

Bureaucrat::~Bureaucrat(){
};

/*-----------------------getter / setter -----------------------------*/

int Bureaucrat::getGrade() const{
	return this->_grade;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}
/*-----------------------Function-----------------------------*/

void Bureaucrat::dgrade(){
	try{
		this->_grade++;
		this->check_grade();
	}
	catch (const Bureaucrat::GradeTooHighException& e){
		this->_grade--;
		std::cerr << e.what() << std::endl;}
	catch (const Bureaucrat::GradeTooLowException& e){
		this->_grade--;
		std::cerr << e.what() << std::endl;}
	catch (...){
		this->_grade--;
		std::cerr << "Unknow" << std::endl;}
}

void Bureaucrat::igrade(){
	try{
		this->_grade--;
		this->check_grade();
	}
	catch (const Bureaucrat::GradeTooHighException& e){
		this->_grade++;
		std::cerr << e.what() << std::endl;}
	catch (const Bureaucrat::GradeTooLowException& e){
		this->_grade++;
		std::cerr << e.what() << std::endl;}
	catch (...){
		this->_grade++;
		std::cerr << "Unknow" << std::endl;}
	
}

void Bureaucrat::check_grade() const{

	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form){
	try {
		
		form.beSigned(*this);
		std::cout << "\e[3m\e[34m [" << this->getName() << "] signed " << form.getName() << "\e[0m" << std::endl;
	}
	catch (const AForm::GradeTooHighException& e){
		std::cout	<< "\e[3m\e[31m ["
					<< this->getName()
					<< "] couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< "\e[0m"
					<< std::endl;}

	catch (const AForm::GradeTooLowException& e){
		std::cout	<< "\e[3m\e[31m ["
					<< this->getName()
					<< "] couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< "\e[0m"
					<< std::endl;}
	catch (...){
		std::cout << "Unknow" << std::endl;}
}



void		Bureaucrat::executeForm(AForm const& form){
	try{
		form.execute(*this);
		std::cout << "\e[3m\e[34m [" << this->getName() << "] executed " << form.getName () << "\e[0m" << std::endl;
	}
	catch (const AForm::GradeTooHighException& e){
		std::cerr	<< "\e[3m\e[31m ["
					<< this->getName()
					<< "] couldn't execute "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< "\e[0m"
					<< std::endl;}

	catch (const AForm::GradeTooLowException& e){
		std::cerr	<< "\e[3m\e[31m ["
					<< this->getName()
					<< "] couldn't execute "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< "\e[0m"
					<< std::endl;}

	catch (const AForm::InvalidFileException& e){
		std::cerr	<< "\e[3m\e[31m ["
					<< this->getName()
					<< "] couldn't execute "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< "\e[0m"
					<< std::endl;}

	catch (const AForm::FormNotSignedException& e){
		std::cerr	<< "\e[3m\e[31m ["
					<< this->getName()
					<< "] couldn't execute "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< "\e[0m"
					<< std::endl;}

	catch (...){
		std::cerr << "Unknow" << std::endl;}
}

/*-----------------------exception-----------------------------*/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("[Error]\n Grade too high");
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("[Error]\n Grade too low");
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs){
	o << rhs.getName() << ", bureaucrat grade : " << rhs.getGrade() << std::endl;
	return o; 
}
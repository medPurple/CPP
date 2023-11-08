#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("stagiaire"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) :  _name(name), _grade(grade){
	this->check_grade();};

Bureaucrat::Bureaucrat(const Bureaucrat &rhs):  _name(rhs.getName()), _grade(rhs.getGrade()){};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
	this->_grade = rhs.getGrade();
	const_cast<std::string&>(this->_name) = rhs.getName();
	return *this;
};

Bureaucrat::~Bureaucrat(){
};

int Bureaucrat::getGrade() const{
	return this->_grade;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}

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

void Bureaucrat::signForm(Form &form){
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const Form::GradeTooHighException& e){
		std::cout	<< this->getName()
					<< " couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< std::endl;}

	catch (const Form::GradeTooLowException& e){
		std::cout	<< this->getName()
					<< " couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< std::endl;}
	catch (...){
		std::cout << "Unknow" << std::endl;}
}

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
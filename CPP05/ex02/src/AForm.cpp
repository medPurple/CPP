#include "AForm.hpp"
#include "Bureaucrat.hpp"


/*-----------------------Coplien-----------------------------------*/

AForm::AForm() :
	_name("AForm"),
	_is_signed(false),
	_require_grade_s(0),
	_require_grade_e(0)
{};

AForm::AForm(std::string name, int gradeS, int gradeE) :
	_name(name),
	_is_signed(false),
	_require_grade_s(gradeS),
	_require_grade_e(gradeE)
{};

AForm::AForm(const AForm &rhs) :
	_name(rhs.getName()),
	_is_signed(rhs.isSigned()),
	_require_grade_s(rhs.getGradeS()),
	_require_grade_e(rhs.getGradeE())
{};

AForm &AForm::operator=(const AForm &rhs)
{
	const_cast<std::string&>(this->_name) = rhs.getName();
	this->_is_signed = rhs.isSigned();
	const_cast<int&>(this->_require_grade_e) = rhs.getGradeE();
	const_cast<int&>(this->_require_grade_s) = rhs.getGradeS();
	return *this;
};

AForm::~AForm(){
};

/*-------------------------Operator--------------------------------*/

std::ostream& operator<<(std::ostream& o, const AForm& rhs){
	o	<< "Name : " << rhs.getName() << std::endl
		<< "Signed ? " << (rhs.isSigned() ? "true" : "false") << std::endl
		<< "Grade to sign : " << rhs.getGradeS() << std::endl
		<< "Grade to execute : " << rhs.getGradeE() << std::endl
		<< std::endl;
	return o; 
}


/*-------------------------Getter----------------------------------*/


std::string AForm::getName() const{
	return this->_name;
}

bool		AForm::isSigned() const{
	return this->_is_signed;
}

int			AForm::getGradeS() const{
	return this->_require_grade_s;
}

int			AForm::getGradeE() const{
	return this->_require_grade_e;
}

/*-------------------------Exceptions--------------------------*/

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
};

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
};

/*-------------------------Fonctions-----------------------------*/


void AForm::beSigned(Bureaucrat ppl){
	if (ppl.getGrade() > this->getGradeS())
		throw GradeTooLowException();
	if (ppl.getGrade() < 0)
		throw GradeTooHighException();
	_is_signed = true;
}
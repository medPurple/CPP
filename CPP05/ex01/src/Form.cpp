#include "Form.hpp"
#include "Bureaucrat.hpp"


/*-----------------------Coplien-----------------------------------*/

Form::Form() :
	_name("Form"),
	_is_signed(false),
	_require_grade_s(0),
	_require_grade_e(0)
{/*std::cout << FDconst << std::endl;*/};

Form::Form(std::string name, int gradeS, int gradeE) :
	_name(name),
	_is_signed(false),
	_require_grade_s(gradeS),
	_require_grade_e(gradeE)
{/*std::cout << FPconst << std::endl;*/};

Form::Form(const Form &rhs) :
	_name(rhs.getName()),
	_is_signed(rhs.isSigned()),
	_require_grade_s(rhs.getGradeS()),
	_require_grade_e(rhs.getGradeE())
	{/*std::cout << FCconst << std::endl;*/};

Form &Form::operator=(const Form &rhs)
{
	//std::cout << FAop << std::endl;
	const_cast<std::string&>(this->_name) = rhs.getName();
	this->_is_signed = rhs.isSigned();
	const_cast<int&>(this->_require_grade_e) = rhs.getGradeE();
	const_cast<int&>(this->_require_grade_s) = rhs.getGradeS();
	return *this;
};

Form::~Form(){
	//std::cout << FDdest << std::endl;
};

/*-------------------------Operator--------------------------------*/

std::ostream& operator<<(std::ostream& o, const Form& rhs){
	o	<< "Name : " << rhs.getName() << std::endl
		<< "Signed ? " << (rhs.isSigned() ? "true" : "false") << std::endl
		<< "Grade to sign : " << rhs.getGradeS() << std::endl
		<< "Grade to execute : " << rhs.getGradeE() << std::endl
		<< std::endl;
	return o; 
}


/*-------------------------Getter----------------------------------*/


std::string Form::getName() const{
	return this->_name;
}

bool		Form::isSigned() const{
	return this->_is_signed;
}

int			Form::getGradeS() const{
	return this->_require_grade_s;
}

int			Form::getGradeE() const{
	return this->_require_grade_e;
}

/*-------------------------Exceptions--------------------------*/

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
};

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
};

/*-------------------------Fonctions-----------------------------*/


void Form::beSigned(Bureaucrat ppl){
	if (ppl.getGrade() > this->getGradeS())
		throw GradeTooLowException();
	if (ppl.getGrade() < 0)
		throw GradeTooHighException();
	_is_signed = true;
}
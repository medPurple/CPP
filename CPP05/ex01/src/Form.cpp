#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_name("Form"),
	_is_signed(false),
	_require_grade_e(0),
	_require_grade_s(0)
{std::cout << FDconst << std::endl;};

Form::Form(std::string name, bool issigned, int gradeS, int gradeE) :
	_name(name),
	_is_signed(issigned),
	_require_grade_e(gradeE),
	_require_grade_s(gradeS)
{std::cout << FPconst << std::endl;};

Form::Form(const Bureaucrat &rhs){
	std::cout << FCconst << std::endl;
};

Form &Form::operator=(const Bureaucrat &rhs){
	std::cout << FAop << std::endl;
	return *this;
};

Form::~Form(){
	std::cout << FDdest << std::endl;
};
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "Construction ok\n" << std::endl;

	Bureaucrat tmp("Bob", 1);
	Bureaucrat tmp1("Maurice", 150);
	
	std::cout << std::endl;
	std::cout << tmp;
	std::cout << tmp1;
	std::cout << std::endl;

	std::cout << "Construction nok\n" << std::endl;

	Bureaucrat tmp2("toohigh", 0);

	Bureaucrat tmp3("toolow", 151);
	std::cout << std::endl;

	std::cout << tmp2;
	std::cout << tmp3;

	std::cout << std::endl;

	std::cout << "INCREMENTATION / DECREMENTATION\n" << std::endl;

	tmp.igrade();
	std::cout << std::endl;

	tmp1.dgrade();
	std::cout << std::endl;

	std::cout << tmp;
	std::cout << tmp1;

	std::cout << std::endl;

}
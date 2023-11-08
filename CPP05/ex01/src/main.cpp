#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "Construction ok\n" << std::endl;

	Bureaucrat tmp("Bob", 1);
	Bureaucrat tmp1("Maurice", 149);
	Form		tmp2("file",50,50);
	Form		tmp3("file2",150,50);
	
	std::cout << std::endl;

	std::cout << tmp;
	std::cout << tmp1;
	std::cout << tmp2;
	std::cout << tmp3;

	tmp1.signForm(tmp2);
	std::cout << tmp2;
	tmp.signForm(tmp2);
	std::cout << tmp2;
	
	tmp.signForm(tmp3);
	std::cout << tmp3;
	tmp1.signForm(tmp3);
	std::cout << tmp3;


}
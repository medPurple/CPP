#include <iostream>

int main(void)
{
	std::string string 		= "HI THIS IS BRAIN";
	std::string *stringPTR 	= &string;
	std::string &stringREF	= string;

	std::cout << "Address string " << &string << std::endl;
	std::cout << "Address PTR " << stringPTR << std::endl;
	std::cout << "Address REF " << &stringREF << std::endl;

	std::cout << "String value " << string << std::endl;
	std::cout << "PTR value " << *stringPTR << std::endl;
	std::cout << "REF value " << stringREF << std::endl;
}
#include "identify.hpp"

Base::~Base(){};

Base * generate(void) {
	
	std::srand(std::time(0));
	int valeur = std::rand()%3;
	switch (valeur) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Class A detected !" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Class B detected !" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Class C detected !" << std::endl;
	else
		std::cout << "No class detected !" << std::endl;
}

void identify(Base& p){
	try{(void)dynamic_cast<A&>(p); std::cout <<  "Class A detected !" << std::endl;}
	catch (std::exception &e){}

	try{(void)dynamic_cast<B&>(p); std::cout <<  "Class B detected !" << std::endl;}
	catch (std::exception &e){}

	try{(void)dynamic_cast<C&>(p); std::cout <<  "Class C detected !" << std::endl;}
	catch (std::exception &e){}
}
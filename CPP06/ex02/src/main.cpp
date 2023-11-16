#include "identify.hpp"

int main(void){
	
	Base *tmp = generate();
	Base &tmp2 = *tmp;

	identify(tmp);
	identify(tmp2);

	delete tmp;
	return 0;
}
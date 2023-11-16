#include "Serialization.hpp"

int main(void){
	Data test;
	Data *test2;
	uintptr_t raw;

	test.age = 18;
	test.name = "test";
	test.size = 180;
	test.unknow = true;

	std::cout 	<< "Adress test : " << &test
				<< " AGE : " << test.age
				<< " NAME : " << test.name
				<< " SIZE : " << test.size
				<< " UNKNOW : " << test.unknow << std::endl;
	raw = Serialization::serialize(&test);
	test2 = Serialization::deserialize(raw);
	
	std::cout 	<< "Adress test2 : " << &test2 
				<< " AGE : " << test2->age
				<< " NAME : " << test2->name
				<< " SIZE : " << test2->size
				<< " UNKNOW : " << test2->unknow << std::endl;
	return 0;
}
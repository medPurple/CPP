#include "dog.hpp"
#include "cat.hpp"
#include "animal.hpp"


int main(void)
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << std::endl;

	std::cout << "[ " << dog->get_type() << " ]\t";
	dog->makeSound();
	std::cout << "[ " << cat->get_type() << " ]\t";
	cat->makeSound();


	std::cout << std::endl;

	delete dog;
	delete cat;

	std::cout << std::endl;

	return 0;
}
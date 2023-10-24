#include "dog.hpp"
#include "cat.hpp"
#include "animal.hpp"
#include "wrong_animal.hpp"
#include "wrong_cat.hpp"

int main(void)
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const Animal* other = new Animal();

	std::cout << std::endl;

	std::cout << "[ " << dog->get_type() << " ]\t";
	dog->makeSound();
	std::cout << "[ " << cat->get_type() << " ]\t";
	cat->makeSound();
	std::cout << "[ " << other->get_type() << " ]\t";
	other->makeSound();

	std::cout << std::endl;

	delete dog;
	delete cat;
	delete other;

	std::cout << std::endl;

	const Wrong_Animal* wcat = new Wrong_Cat();
	const Wrong_Animal* wother = new Wrong_Animal();

	std::cout << std::endl;

	std::cout << "[ " << wcat->get_type() << " ]\t";
	wcat->makeSound();
	std::cout << "[ " << wother->get_type() << " ]\t";
	wother->makeSound();

	std::cout << std::endl;

	delete wcat;
	delete wother;

	return (0);
}
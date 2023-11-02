#include "dog.hpp"
#include "cat.hpp"
#include "animal.hpp"

int main(void)
{
	std::cout << "\tBase Constructor" << std::endl;
	std::cout << "\n[Dog]\n" << std::endl;
	const Animal* j = new Dog();
	std::cout << "\n[Cat]\n" << std::endl;	
	const Animal* i = new Cat();
	std::cout << "\n[Animal]\n" << std::endl;
	const Animal* k = new Animal();

	std::cout << "\n\tBase Destructor" << std::endl;
	std::cout << "\n[Dog]\n" << std::endl;
	delete j;
	std::cout << "\n[Cat]\n" << std::endl;
	delete i;
	std::cout << "\n[Animal]\n" << std::endl;
	delete k;

	std::cout << "\n\Different Constructor" << std::endl;	

	std::cout << "\n[Stack Cat]\n" << std::endl;
	Cat cat;
	cat.fill_brain();
	std::cout << "BRAIN CAT " << cat.show_brain() << std::endl;

	std::cout << "\n[Attribution Cat]\n" << std::endl;	
	Cat A_cat = cat;
	std::cout << "BRAIN CAT " << A_cat.show_brain() << std::endl;

	std::cout << "\n[Copy Cat]\n" << std::endl;	
	Cat C_cat(cat);
	std::cout << "BRAIN CAT " << C_cat.show_brain() << std::endl;

	std::cout << "\n[Stack Dog]\n" << std::endl;	

	Dog dog;
	dog.fill_brain();
	std::cout << "BRAIN DOG " << dog.show_brain() << std::endl;

	std::cout << "\n[Stack Dog]\n" << std::endl;	
	Dog A_dog = dog;
	std::cout << "BRAIN DOG " << A_dog.show_brain() << std::endl;
	
	std::cout << "\n[Stack Dog]\n" << std::endl;	
	Dog C_dog(dog);
	std::cout << "BRAIN DOG " << C_dog.show_brain() << std::endl;


	std::cout << "\n Tableau \n" << std::endl;
	Animal *tab[10];

	for (int a = 0; a < 10; a++)
	{
		std::cout << "[Creation]-------------" << a << std::endl;
		if (a < 5)
			tab[a] = new Dog();
		else
			tab[a] = new Cat();
	}
	for (int a = 0; a < 10; a++)
	{
		std::cout << "[Destruction]------------" << a << std::endl;
		delete tab[a];
	}

	std::cout << "\t\n Destructor\n" << std::endl;
	return (0);
}
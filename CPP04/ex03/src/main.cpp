#include "amateria.hpp"
#include "character.hpp"
#include "spell.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	IMateriaSource* csrc(src);
	std::cout << std::endl;
	IMateriaSource* asrc = src;
	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	src->showMateria();
	csrc->showMateria();
	asrc->showMateria();
	std::cout << std::endl;


	ICharacter* me = new Character("me");
	std::cout << std::endl;
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("test");
	std::cout << std::endl;
	me->equip(tmp);

	std::cout << std::endl;
	ICharacter* toome(me);
	std::cout << std::endl;
	ICharacter* threeme = me;
	std::cout << std::endl;

	me->showInv();
	toome->showInv();
	threeme->showInv();
	std::cout << std::endl;

	
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	std::cout << std::endl;

	me->showInv();

	AMateria* tmp1;
	AMateria* tmp2;
	AMateria* tmp3;

	tmp1 = me->stuff_adress(0);
	me->unequip(0);
	std::cout << std::endl;
	me->showInv();
	std::cout << std::endl;

	tmp2 = me->stuff_adress(1);
	me->unequip(1);
	std::cout << std::endl;
	me->showInv();
	std::cout << std::endl;

	tmp3 = me->stuff_adress(2);
	me->unequip(2);
	std::cout << std::endl;
	me->showInv();
	std::cout << std::endl;

	std::cout << std::endl;
	delete tmp1;
	delete tmp2;
	delete tmp3;
	std::cout << std::endl;



	delete bob;
	delete me;
	delete src;
	return 0;
}
#include "../include/MateriaCure.h"
#include "../include/MateriaIce.h"
#include "../include/Character.h"
#include "../include/MateriaSource.h"

int main() {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new MateriaIce());
	src->learnMateria(new MateriaCure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;

}

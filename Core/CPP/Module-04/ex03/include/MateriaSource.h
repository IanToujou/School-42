#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H
#include "IMateriaSource.h"

class MateriaSource: public IMateriaSource {
	AMateria *materiaList[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &src);
	~MateriaSource();
	void learnMateria(AMateria *materia);
	AMateria* createMateria(const std::string &type);
};

#endif
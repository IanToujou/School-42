#ifndef MATERIAICE_H
#define MATERIAICE_H
#include "AMateria.h"

class MateriaIce: public AMateria {
public:
	MateriaIce();
	MateriaIce(const MateriaIce &src);
	MateriaIce &operator=(const MateriaIce &src);
	~MateriaIce();
	AMateria *clone() const;
	void use(ICharacter& target);
};

#endif
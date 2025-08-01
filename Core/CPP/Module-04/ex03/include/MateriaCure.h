#ifndef MATERIACURE_H
#define MATERIACURE_H
#include "AMateria.h"

class MateriaCure: public AMateria {
public:
	MateriaCure();
	MateriaCure(const MateriaCure &src);
	MateriaCure &operator=(const MateriaCure &src);
	~MateriaCure();
	AMateria *clone() const;
	void use(ICharacter& target);
};

#endif
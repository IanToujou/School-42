#include "MateriaCure.h"

#include <iostream>

MateriaCure::MateriaCure(): AMateria("ice") {}

MateriaCure::MateriaCure(const MateriaCure &src): AMateria(src) {}

MateriaCure &MateriaCure::operator=(const MateriaCure &src) {
	if (&src == this)
		return *this;
	AMateria::operator=(src);
	return *this;
}

MateriaCure::~MateriaCure() {
	AMateria::~AMateria();
}

AMateria *MateriaCure::clone() const {
	return new MateriaCure(*this);
}

void MateriaCure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
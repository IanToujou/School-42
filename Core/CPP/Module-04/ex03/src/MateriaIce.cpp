#include "../include/MateriaIce.h"

#include <iostream>

MateriaIce::MateriaIce(): AMateria("ice") {}

MateriaIce::MateriaIce(const MateriaIce &src): AMateria(src) {}

MateriaIce &MateriaIce::operator=(const MateriaIce &src) {
	if (&src == this)
		return *this;
	AMateria::operator=(src);
	return *this;
}

MateriaIce::~MateriaIce() {
	AMateria::~AMateria();
}

AMateria *MateriaIce::clone() const {
	return new MateriaIce(*this);
}

void MateriaIce::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
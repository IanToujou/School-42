#include "../include/AMateria.h"

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type): type(type) {}

AMateria::AMateria(const AMateria &src): type(src.type) {}

AMateria &AMateria::operator=(const AMateria &src) {
	if (&src == this)
		return *this;
	this->type = src.type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter &target) {

}
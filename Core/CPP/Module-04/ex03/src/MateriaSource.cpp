#include "../include/MateriaSource.h"

MateriaSource::MateriaSource() { // NOLINT(*-pro-type-member-init)
	for (int i = 0; i < 4; i++) {
		materiaList[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) { // NOLINT(*-pro-type-member-init)
	for (int i = 0; i < 4; i++) {
		if (src.materiaList[i]) materiaList[i] = src.materiaList[i]->clone();
		else materiaList[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	if (this == &src)
		return *this;
	for (int i = 0; i < 4; i++) {
		delete materiaList[i];
		materiaList[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		if (src.materiaList[i]) {
			materiaList[i] = src.materiaList[i]->clone();  // Deep copy using clone()
		} else {
			materiaList[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete materiaList[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (!materia) return;
	for (int i = 0; i < 4; i++) {
		if (!materiaList[i]) {
			materiaList[i] = materia;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	if (type.empty()) return 0;
	for (int i = 0; i < 4; i++) {
		if (materiaList[i] && materiaList[i]->getType() == type) {
			return materiaList[i]->clone();
		}
	}
	return 0;
}
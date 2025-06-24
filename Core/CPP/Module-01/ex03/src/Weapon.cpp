#include "../include/Weapon.h"

Weapon::Weapon(const std::string &type): type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() const {
	return this->type;
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}
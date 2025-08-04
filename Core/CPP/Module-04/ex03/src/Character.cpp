#include "../include/Character.h"

Character::Character(): name("Default") { // NOLINT(*-pro-type-member-init)
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const std::string &name): name(name) { // NOLINT(*-pro-type-member-init)
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character &src): name(src.name) { // NOLINT(*-pro-type-member-init)
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i]) inventory[i] = src.inventory[i]->clone();
		else inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &src) {
	if (this == &src)
		return *this;
	for (int i = 0; i < 4; i++) {
		delete inventory[i];
		inventory[i] = NULL;
	}
	this->name == src.name;
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i]) {
			inventory[i] = src.inventory[i]->clone();  // Deep copy using clone()
		} else {
			inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete inventory[i];
	}
}

std::string const &Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	if (!m) return;
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(const int idx) {
	if (idx >= 0 && idx < 4) {
		inventory[idx] = NULL;
	}
}

void Character::use(const int idx, ICharacter &target) {
	if (idx >= 0 && idx < 3 && inventory[idx]) {
		inventory[idx]->use(target);
	}
}
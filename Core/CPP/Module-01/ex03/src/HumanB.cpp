#include "../include/HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string &name): name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
	if (this->weapon == NULL)
		std::cout << this->name << " attacks with no weapon" << std::endl;
	else std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
#include "../include/HumanA.h"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon): name(name), weapon(&weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
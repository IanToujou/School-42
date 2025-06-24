#include "../include/Zombie.h"

#include <iostream>
#include <ostream>

Zombie::Zombie(const std::string &name) {
	Zombie::name = name;
}

Zombie::Zombie() {};

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " is dead." << std::endl;
};

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	this->name = name;
}

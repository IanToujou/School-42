#include "../include/Zombie.h"

#include <iostream>
#include <ostream>

Zombie::Zombie(const std::string &name) {
	Zombie::name = name;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " is dead." << std::endl;
};

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

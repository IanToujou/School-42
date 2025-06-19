#include "../include/Zombie.h"

Zombie *newZombie(const std::string &name) {
	return new Zombie(name);
}
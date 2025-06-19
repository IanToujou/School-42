#include "../include/Zombie.h"

void randomChump(const std::string& name) {
	const Zombie *zombie = newZombie(name);
	zombie->announce();
	delete zombie;
}
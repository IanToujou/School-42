#include "../include/Zombie.h"

int main() {
	const Zombie *zombie = newZombie("Kevin");
	zombie->announce();
	delete zombie;
	randomChump("Gustav");
	return 0;
}
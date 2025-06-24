#include "../include/Zombie.h"

int main() {
	const int amount = 10;
	const Zombie *zombies = zombieHorde(amount, "Kevin");
	for (int i = 0; i < amount; ++i)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
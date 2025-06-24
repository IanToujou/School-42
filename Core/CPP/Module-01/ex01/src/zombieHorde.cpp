#include <iostream>
#include <bits/ostream.tcc>

#include "../include/Zombie.h"

Zombie *zombieHorde(const int N, const std::string& name) {

	if (N < 1) {
		std::cout << "A zombie horde must contain at least 1 zombie." << std::endl;
		return NULL;
	}

	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);

}

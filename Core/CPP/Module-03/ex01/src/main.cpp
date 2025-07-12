#include "../include/ClapTrap.h"

int main() {

	ClapTrap simon = ClapTrap("Simon");
	ClapTrap axel = ClapTrap("Axel");

	simon.attack("Target 1");
	simon.takeDamage(10);
	simon.attack("Target 2");

	simon.beRepaired(1000);

	axel.beRepaired(10);
	axel.takeDamage(100);
	axel.attack("Target 3");
	axel.beRepaired(1);
	axel.attack("Target 4");

}

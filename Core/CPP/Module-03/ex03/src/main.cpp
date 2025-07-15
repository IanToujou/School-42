#include "../include/ClapTrap.h"
#include "../include/DiamondTrap.h"
#include "../include/FragTrap.h"
#include "../include/ScavTrap.h"

int main() {

	DiamondTrap trap = DiamondTrap("Trap");

	trap.whoAmI();
	trap.highFivesGuys();
	trap.attack("Target 1");
	trap.takeDamage(10);
	trap.beRepaired(10);

}

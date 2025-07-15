#include "../include/ClapTrap.h"

#include <iostream>
#include <ostream>

ClapTrap::ClapTrap(const std::string &name): name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << ": Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << ": Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (hitPoints <= 0)
		std::cout << "ClapTrap " << name << ": I'm dead. Cannot attack." << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ClapTrap " << name << ": I'm out of energy!" << std::endl;
	else {
		energyPoints--;
		std::cout << "ClapTrap " << name << ": Attacking [" << target << "], dealing " << attackDamage << std::endl;
	}
}

void ClapTrap::takeDamage(const unsigned int amount) {
	hitPoints = std::max(0, static_cast<int>(hitPoints - amount));
	std::cout << "ClapTrap " << name << ": I'm taking " << amount << " damage! Health is now: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(const unsigned int amount) {
	hitPoints = std::min(10, static_cast<int>(hitPoints + amount));
	std::cout << "ClapTrap " << name << ": I'm being repaired by " << amount << " points! Health is now: " << hitPoints << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "ClapTrap " << src.name << ": Copy assignment operator called" << std::endl;
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}
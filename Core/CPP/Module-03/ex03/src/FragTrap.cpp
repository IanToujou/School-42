#include "../include/FragTrap.h"

#include <iostream>

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << ": Constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << ": Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	std::cout << "FragTrap " << src.name << ": Copy assignment operator called" << std::endl;
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}

void FragTrap::highFivesGuys() const {
	std::cout << "FragTrap " << name << ": High fives guys!" << std::endl;
}

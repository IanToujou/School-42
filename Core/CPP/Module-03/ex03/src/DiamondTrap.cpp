#include "../include/DiamondTrap.h"

#include <iostream>

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap " << name << ": Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << ": Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {

}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << ": Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout << "DiamondTrap " << src.name << ": Copy assignment operator called" << std::endl;
	this->name = src.name + "_clap_trap";
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap " << this->name << ": I come from the ClapTrap named " << ClapTrap::name << std::endl;
}

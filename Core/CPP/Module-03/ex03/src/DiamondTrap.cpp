#include "../include/DiamondTrap.h"

#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("DefaultDiamondTrap_clap_trap"), ScavTrap(), FragTrap(), name("DefaultDiamondTrap") {
	std::cout << "DiamondTrap " << name << ": Default constructor called" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name), name(name) {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << ": Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name) {
	std::cout << "DiamondTrap " << src.name << ": Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout << "DiamondTrap " << src.name << ": Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	name = src.name;
	ClapTrap::operator=(src);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << ": Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap " << this->name << ": I come from the ClapTrap named " << ClapTrap::name << std::endl;
}
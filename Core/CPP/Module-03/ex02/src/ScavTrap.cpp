#include "../include/ScavTrap.h"

#include <iostream>
#include <ostream>

ScavTrap::ScavTrap(): guarding(false) {
	std::cout << "ScavTrap " << name << ": Default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name), guarding(false) {
	std::cout << "ScavTrap " << name << ": Constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src), guarding(src.guarding) {
	std::cout << "ScavTrap " << src.name << ": Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src): guarding(src.guarding) {
	std::cout << "ScavTrap " << src.name << ": Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << ": Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (hitPoints <= 0)
		std::cout << "ScavTrap " << name << ": I'm dead. Cannot attack." << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ScavTrap " << name << ": I'm out of energy!" << std::endl;
	else {
		energyPoints--;
		std::cout << "ScavTrap " << name << ": Attacking [" << target << "], dealing " << attackDamage << std::endl;
	}
}

void ScavTrap::guardGate() {
	if (this->guarding) {
		std::cout << "ScavTrap " <<this->name << ": Already in guarding mode." << std::endl;
		return;
	}
	this->guarding = true;
	std::cout << "ScavTrap " <<this->name << ": Now in guarding mode." << std::endl;
}

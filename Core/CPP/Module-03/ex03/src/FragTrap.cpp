#include "../include/FragTrap.h"

#include <iostream>

FragTrap::FragTrap() {
	std::cout << "FragTrap " << name << ": Default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
	std::cout << "FragTrap " << name << ": Constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
	std::cout << "FragTrap " << src.name << ": Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << ": Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	if (this == &src)
		return *this;
	std::cout << "FragTrap " << src.name << ": Copy assignment operator called" << std::endl;
	ClapTrap::operator=(src);
	return *this;
}

void FragTrap::highFivesGuys() const {
	std::cout << "FragTrap " << name << ": High fives guys!" << std::endl;
}

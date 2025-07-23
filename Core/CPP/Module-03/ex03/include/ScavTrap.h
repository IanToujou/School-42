#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap: virtual public ClapTrap {
	bool guarding;
public:
	ScavTrap();
	ScavTrap(const ScavTrap &src);
	explicit ScavTrap(const std::string &name);
	ScavTrap &operator=(const ScavTrap &src);
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
};

#endif
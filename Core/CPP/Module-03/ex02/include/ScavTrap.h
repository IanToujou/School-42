#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap: public ClapTrap {
	bool guarding;
public:
	explicit ScavTrap(const std::string &name);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &src);
	void attack(const std::string &target);
	void guardGate();
};

#endif
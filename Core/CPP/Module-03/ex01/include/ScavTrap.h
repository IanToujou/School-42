#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "../../ex00/include/ClapTrap.h"

class ScavTrap: public ClapTrap {
	bool guarding;
public:
	ScavTrap(const std::string &name);
	virtual ~ScavTrap();
	ScavTrap &operator=(const ClapTrap &src);
	void attack(const std::string &target);
	void guardGate();
};

#endif
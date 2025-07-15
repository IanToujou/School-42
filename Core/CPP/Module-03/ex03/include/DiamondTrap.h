#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string name;
public:
	DiamondTrap();
	explicit DiamondTrap(const std::string &name);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &src);
	void attack(const std::string &target);
	void whoAmI() const;
};

#endif
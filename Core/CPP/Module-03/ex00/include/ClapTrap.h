#ifndef CLAPTRAP_H

#define CLAPTRAP_H
#include <string>

class ClapTrap {
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
public:
	explicit ClapTrap(const std::string &name);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap &operator=(const ClapTrap &src);
};

#endif
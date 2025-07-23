#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap: public ClapTrap {
public:
	FragTrap();
	FragTrap(const FragTrap &src);
	explicit FragTrap(const std::string &name);
	FragTrap &operator=(const FragTrap &src);
	~FragTrap();
	void highFivesGuys() const;
};

#endif
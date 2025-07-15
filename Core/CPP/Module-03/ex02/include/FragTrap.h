#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap: public ClapTrap {
public:
	explicit FragTrap(const std::string &name);
	~FragTrap();
	FragTrap &operator=(const FragTrap &src);
	void highFivesGuys() const;
};

#endif
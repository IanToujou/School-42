#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
private:
	std::string name;
	Weapon *weapon;
public:
	explicit HumanB(const std::string &name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon &weapon);
};

#endif

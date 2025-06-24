#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
private:
	std::string name;
	Weapon *weapon;
public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	void attack() const;
};

#endif
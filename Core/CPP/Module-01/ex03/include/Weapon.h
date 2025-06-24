#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
	std::string type;
public:
	explicit Weapon(const std::string &type);
	~Weapon();
	std::string getType() const;
	void setType(const std::string &type);
};

#endif
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

#include "ICharacter.h"

class Character: public ICharacter {
	std::string name;
	AMateria *inventory[4];
public:
	Character();
	explicit Character(const std::string &name);
	Character(const Character &src);
	Character &operator=(const Character &src);
	~Character();
	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
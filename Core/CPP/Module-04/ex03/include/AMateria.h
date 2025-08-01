#ifndef IMATERIA_H
#define IMATERIA_H
#include <string>

#include "ICharacter.h"

class AMateria {
protected:
	AMateria();
	explicit AMateria(const std::string &type);
	std::string type;
public:
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria &src);
	virtual ~AMateria();
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
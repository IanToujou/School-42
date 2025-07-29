#ifndef WRONGCAT_H

# define WRONGCAT_H
# include "WrongAnimal.h"

class WrongCat: public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);
	~WrongCat();
	void makeSound() const;
};

#endif
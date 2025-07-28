#ifndef CAT_H
#define CAT_H
#include "Animal.h"

class Cat: public Animal {
public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &src);
	~Cat();
	void makeSound() const;
};

#endif
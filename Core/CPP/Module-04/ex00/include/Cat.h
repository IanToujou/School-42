#ifndef CAT_H
#define CAT_H
#include "Animal.h"

class Cat: public Animal {
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat &operator=(const Cat &src);
	void makeSound() const;
};

#endif
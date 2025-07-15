#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog: public Animal {
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();
	Dog &operator=(const Dog &src);
	void makeSound() const;
};

#endif
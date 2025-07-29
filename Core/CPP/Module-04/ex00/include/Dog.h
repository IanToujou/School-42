#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	~Dog();
	void makeSound() const;
};

#endif
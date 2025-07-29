#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
	Brain *brain;
public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	~Dog();
	void makeSound() const;
	void showIdeas() const;
	void setIdea(size_t index, const std::string &idea) const;
};

#endif
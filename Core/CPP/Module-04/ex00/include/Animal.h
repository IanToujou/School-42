#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	explicit Animal(const std::string &type);
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
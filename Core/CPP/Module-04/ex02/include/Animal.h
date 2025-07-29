#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

class Animal {
protected:
	Animal();
	explicit Animal(const std::string &type);
	std::string type;
public:
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
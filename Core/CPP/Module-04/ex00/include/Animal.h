#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &copy);
	~Animal();
	Animal &operator=(const Animal &src);
	void makeSound() const;
	std::string getType() const;
};

#endif
#include "../include/Cat.h"

Cat::Cat(): Animal("Cat") {}

Cat::Cat(const Cat &src): Animal(src) {}

Cat &Cat::operator=(const Cat &src) {
	if (this == &src)
		return *this;
	Animal::operator=(src);
	return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

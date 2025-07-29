#include "../include/Animal.h"

Animal::Animal(): type("Default") {
	std::cout << "Animal " << type << ": Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type): type(type) {
	std::cout << "Animal " << type << ": Constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal " << type << ": Copy constructor called" << std::endl;
	this->type = src.type;
}

Animal &Animal::operator=(const Animal &src) {
	std::cout << "Animal " << type << ": Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	this->type = src.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal " << type << ": Destructor called" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal " << type << ": The default animal makes no sound." << std::endl;
}

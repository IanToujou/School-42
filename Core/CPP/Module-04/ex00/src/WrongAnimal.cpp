#include "../include/WrongAnimal.h"

WrongAnimal::WrongAnimal(): type("Default") {
	std::cout << "WrongAnimal " << type << ": Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type): type(type) {
	std::cout << "WrongAnimal " << type << ": Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "WrongAnimal " << type << ": Copy constructor called" << std::endl;
	this->type = src.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	std::cout << "WrongAnimal " << type << ": Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	this->type = src.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << type << ": Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal " << type << ": Wrong animal sounds." << std::endl;
}
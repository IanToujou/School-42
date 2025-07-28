#include "../include/Cat.h"

Cat::Cat(): Animal("Cat") {}

Cat::~Cat() {
	Animal::~Animal();
}

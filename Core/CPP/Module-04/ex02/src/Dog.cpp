#include "../include/Dog.h"

Dog::Dog(): Animal("Dog"), brain(new Brain()) {}

Dog::Dog(const Dog &src): Animal(src), brain(new Brain(*src.brain)) {}

Dog &Dog::operator=(const Dog &src) {
	if (this == &src)
		return *this;
	Animal::operator=(src);
	this->brain = new Brain();
	*this->brain = *src.brain;
	return *this;
}

Dog::~Dog() {
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

void Dog::showIdeas() const {
	for (int i = 0; i < 3; i++)
		std::cout << type << " Idea #" << i << ": " << brain->getIdea(i) << std::endl;
}

void Dog::setIdea(const size_t index, const std::string &idea) const {
	if (index >= 100)
		return;
	brain->setIdea(index, idea);
}

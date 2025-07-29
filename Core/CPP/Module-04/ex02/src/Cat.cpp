#include "../include/Cat.h"

Cat::Cat(): Animal("Cat"), brain(new Brain()) {}

Cat::Cat(const Cat &src): Animal(src), brain(src.brain) {}

Cat &Cat::operator=(const Cat &src) {
	if (this == &src)
		return *this;
	Animal::operator=(src);
	this->brain = new Brain();
	*this->brain = *src.brain;
	return *this;
}

Cat::~Cat() {
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void Cat::showIdeas() const {
	for (int i = 0; i < 3; i++)
		std::cout << type << " Idea #" << i << ":" << brain->getIdea(i) << std::endl;
}

void Cat::setIdea(const size_t index, const std::string &idea) const {
	brain->setIdea(index, idea);
}

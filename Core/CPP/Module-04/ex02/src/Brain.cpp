#include "../include/Brain.h"

Brain::Brain() {
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src) {
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
		if (!src.ideas[i].empty())
			this->ideas[i] = src.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain: Destructor called" << std::endl;
}

std::string Brain::getIdea(const size_t index) const {
	if (index >= 100)
		return "Invalid";
	return ideas[index];
}

const std::string *Brain::getIdeaAddr(const size_t index) const {
	if (index >= 100)
		return NULL;
	const std::string &reference = ideas[index];
	return &reference;
}

void Brain::setIdea(const size_t index, const std::string &idea) {
	if (index >= 100)
		return;
	ideas[index] = idea;
}

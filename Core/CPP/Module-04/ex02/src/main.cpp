#include "../include/Animal.h"
#include "../include/Cat.h"
#include "../include/Dog.h"
#include "../include/Brain.h"

# define loop for (int i = 0; i < 10; i++)

int main() {

	const Animal *animals[10];

	loop {
		if (i % 2) animals[i] = new Cat();
		else animals[i] = new Dog();
	}

	loop std::cout << animals[i]->getType() << std::endl;
	std::cout << std::endl;

	loop delete(animals[i]);

	const Dog *doggo = new Dog();

	doggo->setIdea(0, "I am a dog");
	doggo->setIdea(1, "Something");
	doggo->setIdea(2, "I am hungry");
	doggo->setIdea(101, "Invalid range");

	const Dog *copy = new Dog(*doggo);

	std::cout << std::endl;

	doggo->showIdeas();
	std::cout << std::endl;

	delete(doggo);
	std::cout << std::endl;

	copy->showIdeas();
	delete(copy);

	return (0);
}
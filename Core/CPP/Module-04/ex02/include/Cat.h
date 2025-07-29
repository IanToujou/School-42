#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
	Brain *brain;
public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	~Cat();
	void makeSound() const;
	void showIdeas() const;
	void setIdea(size_t index, const std::string &idea) const;
};

#endif
#ifndef BRAIN_H
#define BRAIN_H
#include <string>
#include <iostream>

class Brain {
std::string ideas[100];
public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	virtual ~Brain();
	std::string getIdea(size_t index) const;
	const std::string *getIdeaAddr(size_t index) const;
	void setIdea(size_t index, const std::string &idea);
};

#endif
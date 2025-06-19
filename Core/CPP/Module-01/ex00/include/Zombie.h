#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
	explicit Zombie(const std::string &name);
	~Zombie();
	void announce() const;
private:
	std::string name;
};

Zombie *newZombie(const std::string &name);
void randomChump(const std::string& name);

#endif
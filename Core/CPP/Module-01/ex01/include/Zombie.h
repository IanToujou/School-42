#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
	explicit Zombie(const std::string &name);
	Zombie();
	~Zombie();
	void announce() const;
	void setName(const std::string &name);
private:
	std::string name;
};

Zombie *zombieHorde(const int N, const std::string& name);

#endif
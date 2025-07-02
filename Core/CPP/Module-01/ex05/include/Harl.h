#ifndef HARL_H

# define HARL_H

#include <string>

class Harl {
	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();
	~Harl();
	void complain(const std::string& level);
};

#endif
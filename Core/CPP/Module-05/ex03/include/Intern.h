#ifndef INTERN_H
#define INTERN_H
#include <string>

#include "AForm.h"

class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();
	AForm *makeForm(const std::string &name, const std::string& target);
};

#endif
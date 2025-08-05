#include "../include/Intern.h"
#include "../include/ShrubberyCreationForm.h"
#include "../include/PresidentialPardonForm.h"
#include "../include/RobotomyRequestForm.h"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	if (this == &src)
		return *this;
	return *this;
}

Intern::~Intern() {}

static AForm *makePresidential(const std::string &target) {
	return new PresidentialPardonForm(target);
}

static AForm *makeRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *makeShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {

	AForm *(*forms[])(const std::string &target) = {&makePresidential, &makeRobotomy, &makeShrubbery};
	const std::string names[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << "." << std::endl;
			return forms[i](target);
		}
	}

	std::cout << "Intern does not know how to create " << name << "." << std::endl;
	return NULL;

}

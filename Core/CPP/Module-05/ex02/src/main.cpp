#include <iostream>
#include <ostream>

#include "../include/Bureaucrat.h"
#include "../include/AForm.h"
#include "../include/ShrubberyCreationForm.h"

int main() {

	const Bureaucrat *bureaucrat = new Bureaucrat("John Smith", 50);
	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");

	std::cout << bureaucrat << std::endl;
	std::cout << shrubbery << std::endl;

	shrubbery->beSigned(*bureaucrat);
	shrubbery->beExecuted(*bureaucrat);

	delete shrubbery;
	delete bureaucrat;

}

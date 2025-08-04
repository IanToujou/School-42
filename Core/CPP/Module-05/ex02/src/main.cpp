#include <iostream>
#include <ostream>

#include "../include/Bureaucrat.h"
#include "../include/Form.h"
#include "../include/ShrubberyCreationForm.h"

int main() {

	const Bureaucrat *bureaucrat = new Bureaucrat("John Smith", 50);
	const ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");

	std::cout << bureaucrat << std::endl;
	std::cout << shrubbery << std::endl;

	shrubbery->beSigned(bureaucrat);
	shrubbery->beExecuted(*bureaucrat);

	delete shrubbery;
	delete bureaucrat;

}

#include <iostream>
#include <ostream>

#include "../include/Bureaucrat.h"
#include "../include/AForm.h"
#include "../include/PresidentialPardonForm.h"
#include "../include/ShrubberyCreationForm.h"

int main() {

	Bureaucrat *bureaucrat = new Bureaucrat("John Smith", 50);
	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
	//PresidentialPardonForm *presidential = new PresidentialPardonForm("Home");

	std::cout << bureaucrat << std::endl;
	std::cout << shrubbery << std::endl;

	bureaucrat->signForm(*shrubbery);
	bureaucrat->executeForm(*shrubbery);

	delete shrubbery;
	delete bureaucrat;

}

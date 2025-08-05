#include <iostream>
#include <ostream>

#include "../include/Bureaucrat.h"

int main() {

	Bureaucrat *bureaucrat = new Bureaucrat("John Smith", 150);

	try {
		bureaucrat->setGrade(0);
	} catch (Bureaucrat::GradeTooHighException &exception) {
		std::cerr << exception.what() << std::endl;
	}

	try {
		bureaucrat->setGrade(200);
	} catch (Bureaucrat::GradeTooLowException &exception) {
		std::cerr << exception.what() << std::endl;
	}

	std::cout << bureaucrat->getGrade() << std::endl;
	std::cout << bureaucrat << std::endl;

	delete bureaucrat;

}

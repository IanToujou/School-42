#include <iostream>
#include <ostream>

#include "../include/Bureaucrat.h"

int main() {

	const Bureaucrat *bureaucrat = new Bureaucrat("John Smith", 0);

	std::cout << bureaucrat->getGrade() << std::endl;
	std::cout << bureaucrat << std::endl;

	delete bureaucrat;

}

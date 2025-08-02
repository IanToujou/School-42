#include <iostream>
#include <ostream>

#include "../include/Bureaucrat.h"

int main() {

	const Bureaucrat *bureaucrat = new Bureaucrat("Balls", 0);

	std::cout << bureaucrat->getGrade() << std::endl;

	std::cout << *bureaucrat << std::endl;

	delete bureaucrat;

}

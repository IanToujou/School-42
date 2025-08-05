#include <iostream>
#include <ostream>

#include "../include/Bureaucrat.h"
#include "../include/Form.h"

int main() {

	const Bureaucrat *bureaucrat = new Bureaucrat("John Smith", 50);
	Form *validForm = new Form("Valid Form", 100, 100);
	Form *highForm = new Form("High Form", 5, 100);

	std::cout << bureaucrat->getGrade() << std::endl;
	std::cout << bureaucrat << std::endl;

	std::cout << validForm << std::endl;
	std::cout << highForm << std::endl;

	validForm->beSigned(*bureaucrat);
	highForm->beSigned(*bureaucrat);

	delete bureaucrat;
	delete validForm;
	delete highForm;

}

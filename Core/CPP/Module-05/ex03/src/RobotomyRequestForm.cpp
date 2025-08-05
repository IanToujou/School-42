#include "../include/RobotomyRequestForm.h"
#include "../include/AForm.h"
#include "cstdlib"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted(const Bureaucrat &executor) const {
	if (executor.getGrade() > minExecuteGrade)
		throw Bureaucrat::GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
	std::cout << "* Drilling noises *" << std::endl;
	static bool seeded = false;
	if (!seeded) {
		srand(time(0));
		seeded = true;
	}
	if (rand() % 2 == 0) std::cout << "Robotomy failed for " << target << "." << std::endl;
	else std::cout << "Robotomy succeeded for " << target << "." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (&src == this)
		return *this;
	AForm::operator=(src);
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return target;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm *form) {
	os << "Name: " << form->getName() << ", MinSignGrade: " << form->getMinSignGrade() << ", MinExecuteGrade: " << form->getMinExecuteGrade() << ", IsSigned: " << form->getIsSigned() << ".";
	return os;
}
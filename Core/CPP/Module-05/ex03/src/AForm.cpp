#include "../include/AForm.h"

AForm::AForm(): name("DefaultAForm"), minSignGrade(150), minExecuteGrade(150), isSigned(false) {}

AForm::AForm(const std::string &name, const int minSignGrade, const int minExecuteGrade): name(name), minSignGrade(minSignGrade), minExecuteGrade(minExecuteGrade), isSigned(false) {
	if (minSignGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (minExecuteGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (minSignGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (minExecuteGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm &src): name(src.name), minSignGrade(src.minSignGrade), minExecuteGrade(src.minExecuteGrade), isSigned(src.isSigned) {}

AForm &AForm::operator=(const AForm &src) {
	if (&src == this)
		return *this;
	isSigned = src.isSigned;
	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (minSignGrade < bureaucrat.getGrade()) {
		std::cout << bureaucrat.getName() << " couldn't sign AForm " << getName() << " because the grade is too low."  << std::endl;
		return;
	}
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed AForm " << getName() << "." << std::endl;
}

std::string AForm::getName() const {
	return name;
}

int AForm::getMinSignGrade() const {
	return minSignGrade;
}

int AForm::getMinExecuteGrade() const {
	return minExecuteGrade;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

std::ostream &operator<<(std::ostream &os, const AForm *form) {
	os << "Name: " << form->getName() << ", MinSignGrade: " << form->getMinSignGrade() << ", MinExecuteGrade: " << form->getMinExecuteGrade() << ", IsSigned: " << form->getIsSigned() << "."  << std::endl;
	return os;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}
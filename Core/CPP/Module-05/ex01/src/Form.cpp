#include "../include/Form.h"

Form::Form(): name("DefaultForm"), minSignGrade(150), minExecuteGrade(150), isSigned(false) {}

Form::Form(const std::string &name, const int minSignGrade, const int minExecuteGrade): name(name), minSignGrade(150), minExecuteGrade(150), isSigned(false) {
	if (minSignGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (minExecuteGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (minSignGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (minExecuteGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &src): name(src.name), minSignGrade(src.minSignGrade), minExecuteGrade(src.minExecuteGrade), isSigned(src.isSigned) {}

Form &Form::operator=(const Form &src) {
	if (&src == this)
		return *this;
	isSigned = src.isSigned;
	return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (minSignGrade < bureaucrat.getGrade()) {
		std::cout << bureaucrat.getName() << " couldn't sign form " << getName() << " because the grade is too low.";
		return;
	}
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed form " << getName() << ".";
}

std::string Form::getName() const {
	return name;
}

int Form::getMinSignGrade() const {
	return minSignGrade;
}

int Form::getMinExecuteGrade() const {
	return minExecuteGrade;
}

bool Form::getIsSigned() const {
	return isSigned;
}

std::ostream &operator<<(std::ostream &os, const Form *form) {
	os << "Name: " << form->getName() << ", MinSignGrade: " << form->getMinSignGrade() << ", MinExecuteGrade: " << form->getMinExecuteGrade() << ", IsSigned: " << form->getIsSigned() << ".";
	return os;
}
#include "../include/PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 72, 45), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 72, 45), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src), target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beExecuted(const Bureaucrat &executor) const {
	if (executor.getGrade() > minExecuteGrade)
		throw Bureaucrat::GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (&src == this)
		return *this;
	AForm::operator=(src);
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return target;
}
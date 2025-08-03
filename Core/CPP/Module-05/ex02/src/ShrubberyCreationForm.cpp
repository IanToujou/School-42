#include "../include/ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > minExecuteGrade)
		throw Bureaucrat::GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
	std::ofstream out(target + "_shrubbery.txt");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (&src == this)
		return *this;
	AForm::operator=(src);
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return target;
}


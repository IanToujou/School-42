#include "../include/ShrubberyCreationForm.h"
#include "../include/AForm.h"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &executor) const {
	if (executor.getGrade() > minExecuteGrade)
		throw Bureaucrat::GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
	const std::string name = target + "_shrubbery";
	std::ofstream file(name.c_str());
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
	file.close();
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

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm *form) {
	os << "Name: " << form->getName() << ", MinSignGrade: " << form->getMinSignGrade() << ", MinExecuteGrade: " << form->getMinExecuteGrade() << ", IsSigned: " << form->getIsSigned() << ".";
	return os;
}
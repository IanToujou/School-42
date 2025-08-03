#include "../include/Bureaucrat.h"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name): name(name), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade): name(name), grade(150) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name), grade(src.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this == &src)
		return *this;
	grade = src.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade(const int amount) {
	grade -= amount;
}

void Bureaucrat::decrementGrade(const int amount) {
	grade += amount;
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::setGrade(const int amount) {
	if (amount < 1)
		throw GradeTooHighException();
	if (amount > 150)
		throw GradeTooLowException();
	grade = amount;
}

void Bureaucrat::signForm(const Form &form) {
	form.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat *bureaucrat) {
	os << bureaucrat->getName() << ", bureaucrat grade " << bureaucrat->getGrade() << ".";
	return os;
}
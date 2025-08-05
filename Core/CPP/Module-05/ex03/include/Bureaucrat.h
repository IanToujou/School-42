#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <string>
#include <iostream>

#include "AForm.h"

class AForm;

class Bureaucrat {
	const std::string name;
	int grade;
public:
	Bureaucrat();
	explicit Bureaucrat(const std::string &name);
	explicit Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();
	void incrementGrade(int amount);
	void decrementGrade(int amount);
	std::string getName() const;
	int getGrade() const;
	void setGrade(int amount);
	void signForm(AForm &form) const;
	void executeForm(AForm &form) const;
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat *bureaucrat);

#endif
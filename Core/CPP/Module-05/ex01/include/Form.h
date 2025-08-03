#ifndef FORM_H
#define FORM_H
#include <string>

#include "Bureaucrat.h"

class Form {
	const std::string name;
	const int minSignGrade;
	const int minExecuteGrade;
	bool isSigned;
public:
	Form();
	Form(const std::string &name, int minSignGrade, int minExecuteGrade);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();
	void beSigned(const Bureaucrat &bureaucrat);
	std::string getName() const;
	int getMinSignGrade() const;
	int getMinExecuteGrade() const;
	bool getIsSigned() const;
};

std::ostream &operator<<(std::ostream &os, Form *form);

#endif
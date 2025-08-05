#ifndef AFORM_H
#define AFORM_H
#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm {
protected:
	AForm();
	AForm(const std::string &name, int minSignGrade, int minExecuteGrade);
	const std::string name;
	const int minSignGrade;
	const int minExecuteGrade;
	bool isSigned;
public:
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void beExecuted(const Bureaucrat &bureaucrat) const = 0;
	std::string getName() const;
	int getMinSignGrade() const;
	int getMinExecuteGrade() const;
	bool getIsSigned() const;
	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm *form);

#endif
#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.h"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	ShrubberyCreationForm();
	const std::string target;
public:
	explicit ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	void beExecuted(const Bureaucrat &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm *form);

#endif
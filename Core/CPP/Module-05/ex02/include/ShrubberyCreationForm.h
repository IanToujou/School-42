#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.h"

class ShrubberyCreationForm : public AForm {
	ShrubberyCreationForm();
	const std::string target;
public:
	explicit ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm *form);

#endif
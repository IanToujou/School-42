#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.h"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm {
	PresidentialPardonForm();
	const std::string target;
public:
	explicit PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	~PresidentialPardonForm();
	void beExecuted(const Bureaucrat &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm *form);

#endif
#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.h"

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

#endif
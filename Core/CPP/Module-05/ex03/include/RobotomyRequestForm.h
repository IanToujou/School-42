#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.h"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
	RobotomyRequestForm();
	const std::string target;
public:
	explicit RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	~RobotomyRequestForm();
	void beExecuted(const Bureaucrat &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm *form);

#endif
#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.h"

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

#endif
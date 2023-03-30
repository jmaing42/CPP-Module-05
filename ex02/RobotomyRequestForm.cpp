#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), target(copy.target) {}
RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
  static_cast<AForm *>(this)->operator=(copy);
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned())
    throw AForm::NotSignedException();
  if (executor.getGrade() > this->getRequiredGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << "(some drilling noises)" << std::endl;
  if (std::rand() % 2)
    std::cout << this->target << " has been robotomized successfully"
              << std::endl;
  else
    std::cout << "Failed to robotimize " << this->target << std::endl;
}

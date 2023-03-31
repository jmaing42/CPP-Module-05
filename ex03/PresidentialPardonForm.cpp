#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm(copy), target(copy.target) {}
PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
  static_cast<AForm *>(this)->operator=(copy);
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned())
    throw AForm::NotSignedException();
  if (executor.getGrade() > this->getRequiredGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}

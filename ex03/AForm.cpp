#include "AForm.hpp"

#include <ostream>

#include "Bureaucrat.hpp"

void AForm::ensureValidGrade(int grade) {
  if (grade < 1)
    throw AForm::GradeTooHighException();
  if (grade > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int requiredGradeToSign,
             int requiredGradeToExecute)
    : name(name), requiredGradeToSign(requiredGradeToSign),
      requiredGradeToExecute(requiredGradeToExecute) {
  AForm::ensureValidGrade(requiredGradeToSign);
  AForm::ensureValidGrade(requiredGradeToExecute);
}
AForm::~AForm() {}
AForm::AForm(const AForm &copy)
    : name(copy.name), isSigned(copy.isSigned),
      requiredGradeToSign(copy.requiredGradeToSign),
      requiredGradeToExecute(copy.requiredGradeToExecute) {}
AForm &AForm::operator=(const AForm &copy) {
  (void)copy;
  throw AForm::InvalidCopyException();
}

const std::string &AForm::getName() const { return this->name; }
bool AForm::getIsSigned() const { return this->isSigned; }
int AForm::getRequiredGradeToSign() const { return this->requiredGradeToSign; }
int AForm::getRequiredGradeToExecute() const {
  return this->requiredGradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (this->isSigned)
    throw AForm::AlreadySignedException();
  if (bureaucrat.getGrade() > this->requiredGradeToSign)
    throw AForm::GradeTooLowException();
  this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << form.getName() << " require grade " << form.getRequiredGradeToSign()
     << " to sign, require grade " << form.getRequiredGradeToExecute()
     << " to execute.";
  return os;
}

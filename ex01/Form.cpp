#include <ostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void Form::ensureValidGrade(int grade) {
  if (grade < 1)
    throw Form::GradeTooHighException();
  if (grade > 150)
    throw Form::GradeTooLowException();
}

Form::Form(std::string name, int requiredGradeToSign,
           int requiredGradeToExecute)
    : name(name), requiredGradeToSign(requiredGradeToSign),
      requiredGradeToExecute(requiredGradeToExecute) {
  Form::ensureValidGrade(requiredGradeToSign);
  Form::ensureValidGrade(requiredGradeToExecute);
}
Form::~Form() {}
Form::Form(const Form &copy)
    : name(copy.name), isSigned(copy.isSigned),
      requiredGradeToSign(copy.requiredGradeToSign),
      requiredGradeToExecute(copy.requiredGradeToExecute) {}
Form &Form::operator=(const Form &copy) {
  (void)copy;
  throw Form::InvalidCopyException();
}

const std::string &Form::getName() const { return this->name; }
bool Form::getIsSigned() const { return this->isSigned; }
int Form::getRequiredGradeToSign() const { return this->requiredGradeToSign; }
int Form::getRequiredGradeToExecute() const {
  return this->requiredGradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (this->isSigned)
    throw Form::AlreadySignedException();
  if (bureaucrat.getGrade() > this->requiredGradeToSign)
    throw Form::GradeTooLowException();
  this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << form.getName() << " require grade " << form.getRequiredGradeToSign()
     << " to sign, require grade " << form.getRequiredGradeToExecute()
     << " to execute.";
  return os;
}

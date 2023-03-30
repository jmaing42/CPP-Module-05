#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <string>

#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), target(copy.target) {}
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  static_cast<AForm *>(this)->operator=(copy);
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned())
    throw AForm::NotSignedException();
  if (executor.getGrade() > this->getRequiredGradeToExecute())
    throw AForm::GradeTooLowException();
  std::ofstream stream(this->target + "_shrubbery");
  stream << "ASCII trees\n";
  stream.close();
}

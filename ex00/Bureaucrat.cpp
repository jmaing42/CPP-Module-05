#include "Bureaucrat.hpp"

#include <ostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
  setGrade(grade);
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    : name(copy.name), grade(copy.grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
  (void)copy;
  throw Bureaucrat::InvalidCopyException();
}

void Bureaucrat::ensureValidGrade(int grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::setGrade(int grade) {
  Bureaucrat::ensureValidGrade(grade);
  this->grade = grade;
}

const std::string &Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }
void Bureaucrat::increaseGrade() { this->setGrade(this->grade - 1); }
void Bureaucrat::decreaseGrade() { this->setGrade(this->grade + 1); }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}

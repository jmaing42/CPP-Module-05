#ifndef EX02_BUREAUCRAT_HPP_INCLUDED
#define EX02_BUREAUCRAT_HPP_INCLUDED

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
private:
  static void ensureValidGrade(int grade);

  const std::string name;
  int grade;

  void setGrade(int grade);

public:
  Bureaucrat(std::string name = "<name>", int grade = 42);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &copy);
  Bureaucrat &operator=(const Bureaucrat &copy);

  const std::string &getName() const;
  int getGrade() const;
  void increaseGrade();
  void decreaseGrade();
  void signForm(AForm &form) const;
  void executeForm(const AForm &form);

  class GradeRangeException : public std::exception {};
  class GradeTooHighException : public GradeRangeException {};
  class GradeTooLowException : public GradeRangeException {};
  class InvalidCopyException : public std::exception {};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif

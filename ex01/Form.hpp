#ifndef EX01_FORM_HPP_INCLUDED
#define EX01_FORM_HPP_INCLUDED

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form {
private:
  static void ensureValidGrade(int grade);

  const std::string name;
  bool isSigned;
  const int requiredGradeToSign;
  const int requiredGradeToExecute;

public:
  Form(std::string name = "<name>", int requiredGradeToSign = 42,
       int requiredGradeToExecute = 42);
  ~Form();
  Form(const Form &copy);
  Form &operator=(const Form &copy);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getRequiredGradeToSign() const;
  int getRequiredGradeToExecute() const;

  void beSigned(Bureaucrat bureaucrat);

  class GradeRangeException : public std::exception {};
  class GradeTooHighException : public GradeRangeException {};
  class GradeTooLowException : public GradeRangeException {};
  class InvalidCopyException : public std::exception {};
  class AlreadySignedException : public std::exception {};
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif

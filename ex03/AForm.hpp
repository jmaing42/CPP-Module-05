#ifndef EX03_A_FORM_HPP_INCLUDED
#define EX03_A_FORM_HPP_INCLUDED

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  static void ensureValidGrade(int grade);

  const std::string name;
  bool isSigned;
  const int requiredGradeToSign;
  const int requiredGradeToExecute;

public:
  AForm(std::string name = "<name>", int requiredGradeToSign = 42,
        int requiredGradeToExecute = 42);
  virtual ~AForm();
  AForm(const AForm &copy);
  AForm &operator=(const AForm &copy);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getRequiredGradeToSign() const;
  int getRequiredGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeRangeException : public std::exception {};
  class GradeTooHighException : public GradeRangeException {};
  class GradeTooLowException : public GradeRangeException {};
  class InvalidOperationException : public std::exception {};
  class InvalidCopyException : public InvalidOperationException {};
  class AlreadySignedException : public InvalidOperationException {};
  class NotSignedException : public InvalidOperationException {};
};

std::ostream &operator<<(std::ostream &os, const AForm &Form);

#endif

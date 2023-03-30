#ifndef EX02_ROBOTOMY_REQUEST_FORM_HPP_INCLUDED
#define EX02_ROBOTOMY_REQUEST_FORM_HPP_INCLUDED

#include <exception>
#include <ostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
private:
  std::string target;

public:
  RobotomyRequestForm(std::string target = "<target>");
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

  virtual void execute(Bureaucrat const &executor) const;
};

#endif

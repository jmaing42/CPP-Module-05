#ifndef EX02_SHRUBERRY_CREATION_FORM_HPP_INCLUDED
#define EX02_SHRUBERRY_CREATION_FORM_HPP_INCLUDED

#include <exception>
#include <ostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
  std::string target;

public:
  ShrubberyCreationForm(std::string target = "<target>");
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

  virtual void execute(Bureaucrat const &executor) const;
};

#endif

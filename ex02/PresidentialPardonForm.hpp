#ifndef EX02_PRESIDENTIAL_PARDON_FORM_HPP_INCLUDED
#define EX02_PRESIDENTIAL_PARDON_FORM_HPP_INCLUDED

#include <exception>
#include <ostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string target;

public:
  PresidentialPardonForm(std::string target = "<target>");
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

  virtual void execute(Bureaucrat const &executor) const;
};

#endif

#include <cstddef>
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  {
    ShrubberyCreationForm form1;
    ShrubberyCreationForm form2(form1);
    Bureaucrat bureaucrat;
    bureaucrat.executeForm(form1);
    bureaucrat.signForm(form2);
    bureaucrat.executeForm(form2);
  }
  {
    RobotomyRequestForm form;
    Bureaucrat bureaucrat;
    bureaucrat.signForm(form);
    for (size_t i = 0; i < 42; i++)
      bureaucrat.executeForm(form);
  }
  {
    PresidentialPardonForm form;
    Bureaucrat bureaucrat;
    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
    Bureaucrat ten("ten", 10);
    ten.signForm(form);
    ten.executeForm(form);
    Bureaucrat president("president", 1);
    president.signForm(form);
    president.executeForm(form);
  }
}

#ifndef EX03_INTERN_HPP_INCLUDED
#define EX03_INTERN_HPP_INCLUDED

#include "AForm.hpp"

class Intern {
private:
public:
  Intern();
  ~Intern();
  Intern(const Intern &copy);
  Intern &operator=(const Intern &copy);

  AForm *makeForm(std::string type, std::string target);

  class InvalidTargetException : public std::exception {};
};

#endif

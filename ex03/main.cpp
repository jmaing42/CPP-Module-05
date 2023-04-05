#include <cstddef>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
  {
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    delete rrf;
  }
  {
    Intern someRandomIntern;
    AForm *rrf;
    try {
      rrf = someRandomIntern.makeForm("go home", "jmaing");
      delete rrf;
    } catch (const std::exception &e) {
      std::cout << "Error making form: " << e.what() << std::endl;
    }
  }
}

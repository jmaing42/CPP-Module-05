#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  {
    Form form;
    std::cout << form << std::endl;
    try {
      for (Bureaucrat bureaucrat("B", 150);; bureaucrat.increaseGrade()) {
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(form);
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}

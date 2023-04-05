#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  {
    Bureaucrat bureaucrat;
    std::cout << bureaucrat << std::endl;
    try {
      while (true) {
        bureaucrat.increaseGrade();
        std::cout << bureaucrat << std::endl;
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    std::cout << bureaucrat << std::endl;
  }
  {
    Bureaucrat bureaucrat;
    std::cout << bureaucrat << std::endl;
    try {
      while (true) {
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    std::cout << bureaucrat << std::endl;
  }
}

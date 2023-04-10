/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:08:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/01 01:18:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <sys/_types/_size_t.h>

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &copy) { (void)copy; }
Intern &Intern::operator=(const Intern &copy) {
  (void)copy;
  return *this;
}

static AForm *createShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}
static AForm *createRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}
static AForm *createPresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}

struct Entry {
  AForm *(*factory)(std::string target);
  std::string typeName;
};

const Entry typeInfo[] = {
    {createShrubberyCreationForm, "shrubbery creation"},
    {createRobotomyRequestForm, "robotomy request"},
    {createPresidentialPardonForm, "presidential pardon"},
};

AForm *Intern::makeForm(std::string type, std::string target) {
  AForm *(*factory)(std::string target) = NULL;
  for (size_t i = 0; i < sizeof(typeInfo) / sizeof(typeInfo[0]); i++)
    if (typeInfo[i].typeName == type)
      factory = typeInfo[i].factory;
  if (!factory)
    throw Intern::InvalidTargetException();
  std::cout << "Intern creates " << type << std::endl;
  return factory(target);
}

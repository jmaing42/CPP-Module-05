NAME = ex03
OBJS = main.o Bureaucrat.o AForm.o ShrubberyCreationForm.o RobotomyRequestForm.o PresidentialPardonForm.o Intern.o

CXXFLAGS = -Wall -Wextra -Werror


all: $(NAME)
.PHONY: all


.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

NAME = Bureaucrat
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
rm = rm -rf
HEADERS = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp \
			ShrubberyCreationForm.hpp Intern.hpp

SRCS = Bureaucrat.cpp  AForm.cpp  PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp Intern.cpp main.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(rm) $(OBJS)

fclean: clean
	$(rm) $(NAME)
re: fclean all

.PHONY: all clean fclean re
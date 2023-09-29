# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 22:51:56 by ryoshio-          #+#    #+#              #
#    Updated: 2023/09/29 16:24:23 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ex03

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

VALGRIND = valgrind -s  --leak-check=full 

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

HEADER	= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o:	%.cpp $(HEADER)
	@$(CC) $(CFLAG) -c $< -o $@ 


run: all
	$(VALGRIND) ./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re run 

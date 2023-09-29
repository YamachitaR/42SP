# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 22:51:56 by ryoshio-          #+#    #+#              #
#    Updated: 2023/09/15 16:06:24 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ex01

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

VALGRIND = valgrind -s  --leak-check=full 

SRC = main.cpp Bureaucrat.cpp Form.cpp

HEADER	= Bureaucrat.hpp Form.hpp  

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
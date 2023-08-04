# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 22:51:56 by ryoshio-          #+#    #+#              #
#    Updated: 2023/08/01 03:24:14 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ex00

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

VALGRIND = valgrind -s

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp

HEADER	= Animal.hpp Dog.hpp Cat.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

run: all
	$(VALGRIND) ./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re run 
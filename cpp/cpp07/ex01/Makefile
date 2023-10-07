# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 22:51:56 by ryoshio-          #+#    #+#              #
#    Updated: 2023/10/04 22:05:51 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98


SRC = main.cpp

HEADER	=  iter.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o:	%.cpp $(HEADER)
	@$(CC) $(CFLAG) -c $< -o $@ 


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re run 
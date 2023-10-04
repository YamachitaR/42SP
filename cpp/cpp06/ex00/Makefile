# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 22:51:56 by ryoshio-          #+#    #+#              #
#    Updated: 2023/10/03 16:39:32 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert 

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ScalarConverter.cpp 

TSRC = test.cpp ScalarConverter.cpp

HEADER	= ScalarConverter.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o:	%.cpp $(HEADER)
	@$(CC) $(CFLAG) -c $< -o $@ 


test: 
	$(CC) $(CFLAG) $(TSRC) -o test




clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) test

re: fclean all

.PHONY: all clean fclean re run 
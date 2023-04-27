# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 01:57:39 by ryoshio-          #+#    #+#              #
#    Updated: 2023/04/25 19:28:40 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= member


CC = c++

#CFLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp  Sample.class.cpp

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)


run: all
	./$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
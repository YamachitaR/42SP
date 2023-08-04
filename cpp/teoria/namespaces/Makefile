# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 18:05:48 by ryoshio-          #+#    #+#              #
#    Updated: 2023/04/25 19:14:48 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEMPLO1 = exemplo1
EXEMPLO2 = exemplo2

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

SRC1 = exemplo1.cpp  
SRC2 = exemplo2.cpp

OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)

all: $(EXEMPLO1)

$(EXEMPLO1): $(OBJ1) $(OBJ2)
	$(CC) $(CFLAG) $(OBJ1) -o $(EXEMPLO1)
	$(CC) $(CFLAG) $(OBJ2) -o $(EXEMPLO2)

run: all
	./$(EXEMPLO1)
	./$(EXEMPLO2)

clean:
	rm -rf $(OBJ1) $(OBJ2)

fclean: clean
	rm -rf $(EXEMPLO1) $(EXEMPLO2)

re: fclean all

.PHONY: all clean fclean re 
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 22:02:27 by ryoshio-          #+#    #+#              #
#    Updated: 2023/08/04 22:15:55 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ex00

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

VALGRIND = valgrind 

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp 

HEADER = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADER)
	@$(CC) $(CFLAG) -c $< -o $@ 

run: all
	$(VALGRIND) ./$(NAME)
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
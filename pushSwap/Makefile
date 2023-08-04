# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 02:11:42 by ryoshio-          #+#    #+#              #
#    Updated: 2022/06/22 19:18:11 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAG = -g -Wall -Wextra -Werror 

SRC = main.c check_argument.c assign_value.c swap.c push.c\
	rotate.c sort.c reverse_rotate.c

OBJ = ${SRC:.c=.o}
 

 
LIBFT = libft/libft.a

all: $(NAME)


$(NAME): $(LIBRARY) $(OBJ)
	make -C libft
	$(CC) $(CFLAG) $(SRC) $(LIBFT) -o $(NAME)



clean:
	make -C libft clean 
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PYTHON: all clean fclean re 
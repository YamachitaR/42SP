# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 17:03:46 by ryoshio-          #+#    #+#              #
#    Updated: 2022/10/06 00:44:25 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAG = -g -Wall -Wextra -Werror

SRC = main.c check_arg.c  ft_free_strstr.c ft_execve.c open_files.c

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

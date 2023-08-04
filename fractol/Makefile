# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 13:24:07 by ryoshio-          #+#    #+#              #
#    Updated: 2022/04/03 00:31:09 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = fractol.c check_arguments.c fractol_util.c hook.c julia.c mandelbrot.c \
	burning.c color.c


OBJS = ${SRC:.c=.o}
CC = clang
CFLAG = -Wall -Wextra -Werror -g
MLX = minilibx-linux/libmlx.a  -l Xext -l X11 -l m -l bsd
LIBF = libft/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I . -I minilibx-linux -I libft -c $< -o $(<:.c=.o)

bonus: all

$(NAME): $(LIBRARY) $(OBJS)
	make -C minilibx-linux
	make -C libft
	gcc -Wall -Werror -Wextra $(SRC) libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -o fractol



clean:
	make -C libft clean 
	make -C minilibx-linux clean
	rm -rf $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PYTHON: all clean fclean re 
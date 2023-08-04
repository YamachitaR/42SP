# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 00:58:22 by ryoshio-          #+#    #+#              #
#    Updated: 2022/05/01 07:10:14 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}
OBJS_SERVER = ${SRC_SERVER:.c=.o}
CC = clang
CFLAG = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	make -C libft
	$(CC) $(CFLAG) $(SRC_SERVER) $(LIBFT) -o $(SERVER)


$(CLIENT): $(OBJS_CLIENT)
	make -C libft
	$(CC) $(CFLAG) $(SRC_CLIENT) $(LIBFT) -o $(CLIENT)

clean:
	make -C libft clean 
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	make -C ./libft fclean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PYTHON: all clean fclean re 

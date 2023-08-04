# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 02:26:42 by ryoshio-          #+#    #+#              #
#    Updated: 2022/04/02 17:07:54 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strrchr.c\
	ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c\
	ft_strncmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c\
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 ar -crs $(NAME) $(OBJS)

bonus: all

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

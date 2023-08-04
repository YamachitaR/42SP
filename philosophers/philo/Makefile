# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 21:29:36 by ryoshio-          #+#    #+#              #
#    Updated: 2022/12/12 10:30:41 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c error.c \
	ft_atoi.c \
	ft_argv_check.c \
	ft_data_init.c \
	ft_philo.c \
	ft_philo_init.c \
	ft_philo_think.c \
	ft_print.c \
	ft_philo_pthread.c\
	mutex_utils.c \
	ft_monitoring.c \
	ft_philo_sleep.c \
	ft_philo_eat.c \
	ft_clean.c \
	ft_time_epoch_in_ms.c

CC = gcc

CFLAG = -g -Wall -Wextra -Werror #-fsanitize=thread

OBJS =  ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
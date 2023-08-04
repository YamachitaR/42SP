/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:03:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 07:32:35 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_unsigned_integer(char *str);

int	ft_argv_check(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (printf("The amount of argument is wrong!\n"));
	i = 1;
	while (argv[i])
	{
		if (ft_is_unsigned_integer(argv[i]) == 0 || ft_atoi(argv[i]) < 1
			|| ft_atoi(argv[i]) > 2147483647)
			return (printf("The argument value (%s) is wrong!\n", argv[i]));
		i ++;
	}
	return (0);
}

static int	ft_is_unsigned_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i ++;
	}
	return (1);
}

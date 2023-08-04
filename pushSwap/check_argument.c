/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:16:33 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/16 06:51:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int(char *nbr)
{
	int	index;

	index = 0;
	if (nbr[index] == '+' || nbr[index] == '-')
		index ++;
	if (!nbr[index])
		return (0);
	while (nbr[index])
	{
		if (ft_isdigit(nbr[index]) == 0)
			return (0);
		index ++;
	}
	return (1);
}

static int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0 && \
			ft_strlen(argv[i]) == ft_strlen(argv[j]))
				return (1);
			if (argv[i][0] == '+')
			{	
				if (ft_strncmp(argv[i] + 1, argv[j], ft_strlen(argv[i] + 1)) \
				== 0 && ft_strlen(argv[i] + 1) == ft_strlen(argv[j]))
					return (1);
			}	
			j ++;
		}
		i ++;
	}
	return (0);
}

static int	check_size(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '+')
			argv[i]++;
		if (ft_strlen(argv[i]) == 10)
		{
			if (ft_strncmp(argv[i], "2147483647", 10) > 0)
				return (0);
		}
		if (ft_strlen(argv[i]) == 11)
		{
			if (ft_strncmp(argv[i], "-2147483648", 11) > 0)
				return (0);
		}
		if (ft_strlen(argv[i]) > 11)
			return (0);
		i ++;
	}
	return (1);
}

int	check_argument(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_int(argv[i]))
		{
			ft_putendl_fd("Error", 1);
			return (0);
		}
		i ++;
	}
	if (check_duplicate(argc, argv))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (!check_size(argc, argv))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (argc < 2)
		return (0);
	return (1);
}

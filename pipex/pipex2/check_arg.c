/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:23:53 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/06 03:37:04 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_arg(int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_fd("Invalid value of arguments\n", STDERR);
			exit(EXIT_FAILURE);
		}
		i ++;
	}
	if (argc < 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", STDERR);
		exit(EXIT_FAILURE);
	}
	if (!env)
	{
		ft_putstr_fd("Erron in variable env\n", STDERR);
		exit(EXIT_FAILURE);
	}
}

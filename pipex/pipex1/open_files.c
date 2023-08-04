/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:06:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/06 03:49:19 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_files_out(char *str);
static int	open_files_in(char *str);

void	open_files(t_data *data, int argc, char **argv)
{
	data->fdin = open_files_in(argv[1]);
	data->fdout = open_files_out(argv[argc -1]);
	if (data->fdin == -1)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	dup2(data->fdout, STDOUT);
	dup2(data->fdin, STDIN);
}

static int	open_files_out(char *str)
{
	if (access(str, F_OK) == -1)
		return (open(str, O_CREAT | O_WRONLY));
	else
		return (open(str, O_WRONLY | O_TRUNC));
}

static int	open_files_in(char *str)
{
	if (access(str, F_OK | R_OK) == -1)
	{
		ft_putstr_fd(str, 1);
		ft_putendl_fd (": No such file or directory", STDERR);
		return (-1);
	}
	else
		return (open(str, O_RDONLY));
}

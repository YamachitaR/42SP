/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:06:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/06 09:21:05 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_files_out(char *str);
static int	open_files_in(char *str);
static int	here_doc_open(char *str);

void	open_files(t_data *data, int argc, char **argv)
{
	data->fdout = open_files_out(argv[argc -1]);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		data->fdin = here_doc_open(argv[2]);
		unlink(".here_doc");
		data->arg ++;
	}
	else
		data->fdin = open_files_in(argv[1]);
	if (data->fdin == -1)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	dup2(data->fdin, STDIN);
	dup2(data->fdout, STDOUT);
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

static int	here_doc_open(char *str)
{
	char	*line;
	int		fd;

	if (access(".here_doc", F_OK))
		unlink(".here_doc");
	fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = get_next_line(STDIN);
		if (ft_strncmp(line, str, ft_strlen(str)) != 0)
			write (fd, line, ft_strlen(line));
		else
		{
			free (line);
			close(fd);
			return (open(".here_doc", O_RDONLY));
		}
		free(line);
	}
}

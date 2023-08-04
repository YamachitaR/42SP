/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:15:35 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/06 09:18:13 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_data *data, char **argv, char **env);
static void	parent_process(t_data *data, char **argv, char **env);
static void	command_not_found(t_data *data);

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	int		pid;

	check_arg(argc, argv, env);
	data = (t_data *) malloc (sizeof(t_data));
	open_files(data, argc, argv);
	if (pipe(data->pipefd) == -1)
	{
		ft_putendl_fd("pipe fail", STDERR);
		return (-1);
	}
	pid = fork();
	if (pid == 0)
		child_process(data, argv, env);
	else
		parent_process(data, argv, env);
	return (0);
}

static void	child_process(t_data *data, char **argv, char **env)
{	
	close(data->pipefd[0]);
	dup2(data->pipefd[1], STDOUT);
	data->split_cmd = ft_split(argv[2], ' ');
	if (ft_execve(data->split_cmd, env) == -1)
		command_not_found(data);
}

static void	parent_process(t_data *data, char **argv, char **env)
{
	close(data->pipefd[1]);
	dup2(data->pipefd[0], STDIN);
	data->split_cmd = ft_split(argv[3], ' ');
	if (ft_execve(data->split_cmd, env) == -1)
		command_not_found(data);
}

static void	command_not_found(t_data *data)
{
	close(data->fdin);
	close(data->fdout);
	ft_free_strstr(data->split_cmd);
	free(data);
	exit(EXIT_FAILURE);
}

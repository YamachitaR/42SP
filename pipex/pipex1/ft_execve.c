/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:56:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/06 01:09:42 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_command_path(char **path, char *cmd);
static char	**get_path(char **env);

int	ft_execve(char **split_cmd, char **env)
{
	char	**path;
	char	*command_path;

	path = get_path(env);
	if (!path)
	{
		ft_putendl_fd("Not found path", STDERR);
		exit(EXIT_FAILURE);
	}
	command_path = find_command_path(path, split_cmd[0]);
	if (command_path)
		execve(command_path, split_cmd, env);
	ft_free_strstr(path);
	free(command_path);
	return (-1);
}

static char	*find_command_path(char **path, char *cmd)
{
	char	*cmd_path;
	char	*temp;
	int		i;

	if (ft_strchr(cmd, '/') != NULL && access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (path[i] != NULL)
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

static char	**get_path(char **env)
{
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", ft_strlen("PATH=")) != 0 && env[i])
		i++;
	if (ft_strncmp(env[i], "PATH=", ft_strlen("PATH=")) == 0)
		return (ft_split(env[i] + 5, ':'));
	return (NULL);
}

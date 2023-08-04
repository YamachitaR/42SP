/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:13:45 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/06 01:03:55 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define EXIT_FAILURE 1
# define EXIT_SUCESS 2
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_data
{
	int		fdin;
	int		fdout;
	int		pipefd[2];
	char	**split_cmd;
}	t_data;

void	check_arg(int argc, char **argv, char **env);
void	open_files(t_data *data, int argc, char **argv);
int		ft_execve(char **split_cmd, char **env);
void	ft_free_strstr(char **str);
#endif

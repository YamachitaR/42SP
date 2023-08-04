/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 03:10:17 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/06 06:27:10 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_least_line(int fd, char *line)
{
	char	*buffer;
	char	*temp;
	int		size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(line, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		temp = line;
		buffer[size] = '\0';
		line = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	free(buffer);
	return (line);
}

static char	*only_line(char *line)
{
	size_t	size;

	if (line[0] == '\0')
		return (NULL);
	if (ft_strchr(line, '\n'))
	{
		size = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n')) + 1;
		return (ft_substr(line, 0, size));
	}
	else
		return (ft_substr(line, 0, ft_strlen(line)));
}

static char	*upgrade_line(char *line)
{
	size_t	size;
	char	*temp;

	if (ft_strchr(line, '\n'))
	{
		size = ft_strlen(ft_strchr(line, '\n'));
		if (size != 1)
		{
			temp = line;
			line = ft_substr(ft_strchr(temp, '\n'), 1, size - 1);
			free(temp);
			return (line);
		}
	}
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = read_least_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	get_line = only_line(line[fd]);
	line[fd] = upgrade_line(line[fd]);
	return (get_line);
}

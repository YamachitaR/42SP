/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 03:10:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/29 22:45:29 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	if (!str)
		return (0);
	size = 0;
	while (str[size] != '\0')
		size ++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char )c)
			return ((char *)&s[i]);
		i ++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;

	if (!s1 && !s2)
		return (NULL);
	strjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (NULL);
	if (s1)
		ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcpy(strjoin + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (strjoin);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) >= start)
	{
		substring = malloc(len + 1);
		if (substring == NULL)
			return (NULL);
		ft_strlcpy (substring, s + start, len + 1);
	}
	else
	{
		substring = malloc(1);
		substring[0] = '\0';
	}
	return (substring);
}

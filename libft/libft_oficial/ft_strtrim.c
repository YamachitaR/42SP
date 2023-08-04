/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:04:25 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/09/30 04:30:56 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	end;
	size_t	begin;
	char	*strtrim;

	begin = 0;
	if (s == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s);
	while (ft_strrchr(set, s[begin]) != NULL && s[begin] != '\0')
		begin ++;
	if (ft_strlen(s + begin) != 0)
		while (ft_strrchr(set, s[end - 1]) != NULL)
			end --;
	strtrim = malloc(end - begin + 1);
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, s + begin, end - begin + 1);
	return (strtrim);
}

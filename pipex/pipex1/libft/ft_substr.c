/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:39:21 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/03 15:39:12 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) >= start)
	{
		substring = ft_calloc(len + 1, 1);
		if (substring == NULL)
			return (NULL);
		ft_strlcpy (substring, s + start, len + 1);
	}
	else
		substring = ft_strdup("");
	return (substring);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:50:55 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/09/29 04:57:22 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc (ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 06:18:32 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/03 15:38:48 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*strmapi;

	size = ft_strlen(s);
	i = 0;
	strmapi = malloc(size + 1);
	if (strmapi == NULL)
		return (NULL);
	while (i < size)
	{
		strmapi[i] = f(i, s[i]);
		i ++;
	}
	strmapi[size] = '\0';
	return (strmapi);
}

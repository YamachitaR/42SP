/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:36:52 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/03 02:15:08 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	size = ft_strlen(src);
	if (dstsize != 0)
	{
		if (size < dstsize)
			ft_memmove(dst, src, size + 1);
		else
		{
			ft_memmove(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (size);
}

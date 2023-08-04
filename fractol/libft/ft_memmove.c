/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:25:19 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/03 15:37:13 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	step;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		ft_memcpy (dst, src, len);
	else
	{
		step = len;
		while (step > 0)
		{
			((unsigned char *)dst)[step - 1] = ((unsigned char *)src)[step - 1];
			step --;
		}
	}
	return (dst);
}

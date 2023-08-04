/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:54:56 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/03 15:37:07 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	step;

	if (dest == NULL && src == NULL)
		return (NULL);
	step = 0;
	while (step < n)
	{
		((unsigned char *)dest)[step] = ((unsigned char *)src)[step];
		step ++;
	}
	return (dest);
}

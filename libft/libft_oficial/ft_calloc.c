/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:02:06 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/26 05:08:17 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t alloc, size_t size)
{
	void	*ptr;
	size_t	temp;

	if (alloc == 0 || size == 0)
		return (malloc(0));
	temp = alloc * size;
	if (temp / alloc != size)
		return (0);
	ptr = malloc (alloc * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, (alloc * size));
	return (ptr);
}

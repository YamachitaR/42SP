/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:02:06 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/09/22 03:49:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t alloc, size_t size)
{
	void	*ptr;

	ptr = malloc (alloc * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, (alloc * size));
	return (ptr);
}

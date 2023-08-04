/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:28:07 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/03 15:37:19 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	step;

	step = 0;
	while (step < n)
	{
		((unsigned char *)str)[step] = c;
		step ++;
	}
	return (str);
}

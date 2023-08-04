/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:52:13 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/09/29 16:40:50 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_size(int n)
{
	long int	base;
	int			int_size;

	int_size = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		int_size ++;
	}
	base = 1;
	while (n > base)
	{
		int_size ++;
		base = base * 10;
	}
	if (base / 10 < n && base > n)
		return (int_size - 1);
	return (int_size);
}

char	*ft_itoa(int n)
{
	int		j;
	char	*itoa;

	j = ft_int_size(n) - 1;
	itoa = malloc(j + 2);
	if (itoa == NULL)
		return (NULL);
	itoa[j + 1] = '\0';
	if (n == 0)
		itoa[0] = '0';
	if (n < 0)
	{
		itoa[0] = '-';
		itoa[j --] = -(n % 10) + '0';
		n = n / -10;
	}
	while (j > 0)
	{
		itoa[j] = n % 10 + '0';
		n = n / 10;
		j --;
	}
	if (n > 0)
		itoa[0] = n + '0';
	return (itoa);
}

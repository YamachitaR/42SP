/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:23:42 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/11/28 18:23:04 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_int(char *s)
{
	if (s)
		return (write (1, s, ft_strlen (s)));
	else
		return (write (1, "(null)", 6));
}

int	ft_putnbr_int(int nbr)
{
	char	*str;
	int		size;

	str = ft_itoa (nbr);
	size = ft_putstr_int (str);
	free (str);
	return (size);
}

static int	ft_int_size(unsigned int n)
{
	long int		base;
	unsigned int	int_size;

	int_size = 1;
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

int	ft_putunbr_int(unsigned int n)
{
	unsigned int	j;
	char			*utoa;

	j = ft_int_size(n) - 1;
	utoa = malloc(j + 2);
	if (utoa == NULL)
		return (0);
	utoa[j + 1] = '\0';
	if (n == 0)
		utoa[0] = '0';
	while (j > 0)
	{
		utoa[j] = n % 10 + '0';
		n = n / 10;
		j --;
	}
	if (n > 0)
		utoa[0] = n + '0';
	j = ft_putstr_int(utoa);
	free (utoa);
	return (j);
}

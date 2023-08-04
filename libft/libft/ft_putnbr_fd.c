/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 05:16:40 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/10/08 20:14:00 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int long	base(int n)
{
	int long	base;

	base = 1;
	if (n >= 0)
		while (n > base)
			base = base * 10;
	else
	{
		base = -1;
		while (n < base)
			base = base * 10;
	}
	if (n != 1 && n != -1 && n / base != 1)
		base = base / 10;
	return (base);
}

void	ft_putnbr_fd(int n, int fd)
{
	int long	ten;

	if (n != 0)
	{
		ten = base(n);
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd((n / ten) + '0', fd);
			n = -(n % ten);
			ten = -(ten / 10);
		}
		while (ten > 0)
		{
			ft_putchar_fd(n / ten + '0', fd);
			n = n % ten;
			ten = ten / 10;
		}
	}
	else
		ft_putchar_fd ('0', fd);
}

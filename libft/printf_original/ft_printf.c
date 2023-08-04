/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:18:21 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/11/28 17:57:38 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	conversion(va_list variable, char c)
{
	if (c == 'c')
		return (ft_putchar_int (va_arg (variable, int)));
	if (c == 's')
		return (ft_putstr_int (va_arg (variable, char *)));
	if (c == 'p')
		return (ft_putpointer (va_arg (variable, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_int (va_arg (variable, int)));
	if (c == 'u')
		return (ft_putunbr_int (va_arg (variable, unsigned int)));
	if (c == 'x')
		return (puthexa (va_arg (variable, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (puthexa (va_arg (variable, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (write (1, "%", 1));
	if (c != '\0')
		return (write (1, &c, 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	int		i;
	va_list	variable;

	size = 0;
	i = 0;
	va_start (variable, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i ++;
			size += conversion(variable, format[i]);
		}
		else
			size += write(1, &format[i], 1);
		i ++;
	}
	va_end (variable);
	return (size);
}

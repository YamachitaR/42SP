/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 07:38:37 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/11/28 18:25:26 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	basehexa(unsigned long int nbr)
{
	unsigned long int	aux;
	int					base;

	aux = nbr;
	base = 0;
	while (aux)
	{
		aux /= 16;
		base ++;
	}
	return (base);
}

int	puthexa(unsigned long int nbr, char *hexa)
{
	unsigned long int	aux;
	int					base;
	char				*str;

	if (nbr == 0)
		return (write(1, "0", 1));
	base = basehexa (nbr);
	aux = nbr;
	str = malloc ((base + 1) * sizeof (char));
	if (!str)
		return (0);
	str[base] = '\0';
	while (aux)
	{
		str[-- base] = hexa[aux % 16];
		aux /= 16;
	}
	write(1, str, ft_strlen(str));
	free(str);
	return (basehexa(nbr));
}

int	ft_putpointer(void *p)
{
	unsigned long int	nbr;
	int					size;

	nbr = (unsigned long int)p;
	size = write(1, "0x", 2);
	size += puthexa(nbr, "0123456789abcdef");
	return (size);
}

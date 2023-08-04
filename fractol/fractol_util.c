/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 03:49:32 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/03 00:17:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	my_img_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*byte;

	byte = fractol->img_addr + ((y * fractol->img_line_length) \
		+ (x * fractol->img_bits_per_pixel / 8));
	*(unsigned int *)byte = color;
}

double	atf(char *str)
{
	double	atf;
	int		base;
	int		i;

	base = 1;
	i = 1;
	while (i < (int)ft_strlen(ft_strchr(str, '.')))
	{
		base *= 10;
		i ++;
	}
	atf = (float)ft_atoi(str);
	if (!ft_strchr(str, '.'))
		return (atf);
	if (str[0] != '-')
		atf += (float)ft_atoi(ft_strchr(str, '.') + 1) / base;
	else
		atf -= (float)ft_atoi(ft_strchr(str, '.') + 1) / base;
	return (atf);
}

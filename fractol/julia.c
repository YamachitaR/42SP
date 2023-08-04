/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:22:10 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/02 18:06:00 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_julia(t_fractol *fractol, double x, double y);

void	julia(t_fractol *fractol)
{
	double	x;
	double	y;

	fractol->x = 0;
	fractol->y = 0;
	while (fractol->y <= IMG_Y)
	{
		while (fractol->x <= IMG_X)
		{
			x = fractol->x_min + (fractol->x * ((fractol->x_max \
				- fractol->x_min) / IMG_X));
			y = fractol->y_max - (fractol->y * ((fractol->y_max \
				- fractol->y_min) / IMG_Y));
			my_img_pixel_put(fractol, fractol->x, fractol->y, \
				color(set_julia(fractol, x, y), fractol));
			fractol->x++;
		}
		fractol->x = 0;
		fractol->y ++;
	}
}

static int	set_julia(t_fractol *fractol, double x, double y)
{
	double	xz;
	double	yz;
	double	temp;
	int		i;

	i = 1;
	xz = x;
	yz = y;
	while ((xz * xz + yz * yz <= 4) && (i < MAX_ITER))
	{
		i ++;
		temp = xz;
		xz = (xz * xz) - (yz * yz) + fractol->julia_x;
		yz = (2 * temp * yz) + fractol->julia_y;
	}
	if (i == MAX_ITER)
		return (0);
	return (i);
}

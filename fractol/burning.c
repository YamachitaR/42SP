/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:09:36 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/03 00:03:10 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_burning(double x, double y);

void	burning(t_fractol *fractol)
{
	double	x;
	double	y;

	fractol->x = 0;
	fractol->y = 0;
	while (fractol->y <= IMG_Y)
	{
		while (fractol->x <= IMG_X)
		{
			x = fractol->x_min + \
				(fractol->x * ((fractol->x_max - fractol->x_min) / IMG_X));
			y = fractol->y_max - \
				(fractol->y * ((fractol->y_max - fractol->y_min) / IMG_Y));
			my_img_pixel_put(fractol, fractol->x, fractol->y, \
				color(set_burning(x, y), fractol));
			fractol->x++;
		}
		fractol->x = 0;
		fractol->y ++;
	}
}

static int	set_burning(double x, double y)
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
		xz = (xz * xz) - (yz * yz) - x;
		yz = fabs(2 * temp * yz) - y;
	}
	if (i == MAX_ITER)
		return (0);
	return (i);
}

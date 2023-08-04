/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 05:05:31 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/02 18:31:49 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	direction(int keycode, t_fractol *fractol);

int	close_program(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free (fractol->mlx);
	free(fractol->name);
	free(fractol);
	exit(0);
	return (0);
}

static void	direction(int keycode, t_fractol *fractol)
{
	float	dx;
	float	dy;

	if (keycode == 65361 || keycode == 65363)
	{
		dx = (fractol->x_max - fractol->x_min);
		if (keycode == 65361)
			dx *= -1;
		fractol->x_min += dx / 3.0;
		fractol->x_max += dx / 3.0;
	}
	if (keycode == 65362 || keycode == 65364)
	{
		dy = (fractol->y_max - fractol->y_min);
		if (keycode == 65364)
			dy *= -1;
		fractol->y_min += dy / 3.0;
		fractol->y_max += dy / 3.0;
	}
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
		close_program(fractol);
	direction (keycode, fractol);
	change_color(keycode, fractol);
	choose(fractol);
	return (0);
}

int	zoom(int keycode, int x, int y, t_fractol *fractol)
{
	float	dx;
	float	dy;

	dx = (fractol->x_max - fractol->x_min) / 3;
	dy = (fractol->y_max - fractol->y_min) / 3;
	if (keycode == 4)
	{
		fractol->x_min = (fractol->x_min + dx);
		fractol->x_max = (fractol->x_max - dx);
		fractol->y_min = (fractol->y_min + dy);
		fractol->y_max = (fractol->y_max - dy);
	}
	if (keycode == 5)
	{
		fractol->x_min = (fractol->x_min - dx);
		fractol->x_max = (fractol->x_max + dx);
		fractol->y_min = (fractol->y_min - dy);
		fractol->y_max = (fractol->y_max + dy);
	}
	dx = x;
	dy = y;
	choose(fractol);
	return (0);
}

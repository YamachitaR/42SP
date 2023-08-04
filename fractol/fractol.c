/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 03:49:32 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/02 17:57:46 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start_value(t_fractol *fractol, char **str);

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (check_arguments(argc, argv) == 1)
	{
		fractol = (t_fractol *)malloc(sizeof (t_fractol));
		start_value(fractol, argv);
		fractol->mlx = mlx_init();
		fractol->win = mlx_new_window(fractol->mlx, IMG_X, IMG_Y, \
			fractol->name);
		choose(fractol);
		mlx_hook(fractol->win, 17, 1L << 0, &close_program, fractol);
		mlx_key_hook(fractol->win, key_hook, fractol);
		mlx_mouse_hook(fractol->win, zoom, fractol);
		mlx_expose_hook(fractol->win, (void *)choose, fractol);
		mlx_loop(fractol-> mlx);
	}
	return (0);
}

static void	start_value(t_fractol *fractol, char **str)
{
	fractol->name = ft_strjoin("Fractol: ", str[1]);
	fractol->color = 1;
	fractol->x_min = MIN_X;
	fractol->x_max = MAX_X;
	fractol->y_min = MIN_Y;
	fractol->y_max = MAX_Y;
	if (fractol->name[9] == 'j')
	{
		fractol->julia_x = atf(str[2]);
		fractol->julia_y = atf(str[3]);
	}
}

void	choose(t_fractol *fractol)
{
	fractol->img = mlx_new_image(fractol->mlx, IMG_X, IMG_Y);
	fractol->img_addr = (char *)mlx_get_data_addr(fractol->img, \
		&fractol->img_bits_per_pixel, \
		&fractol->img_line_length, &fractol->img_endian);
	if (fractol->name[9] == 'm')
		mandelbrot(fractol);
	if (fractol->name[9] == 'j')
		julia(fractol);
	if (fractol->name[9] == 'b')
		burning(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	mlx_destroy_image(fractol->mlx, fractol->img);
}

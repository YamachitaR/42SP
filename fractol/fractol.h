/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/03 00:18:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define MAX_ITER 100
# define MIN_X -2
# define MAX_X 2
# define MIN_Y -2
# define MAX_Y 2
# define IMG_Y 600.0
# define IMG_X 600.0

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	char	*name;
	int		color;
	int		img_bits_per_pixel;
	int		img_line_length;
	int		img_endian;
	double	x;
	double	y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	julia_x;
	double	julia_y;
}t_fractol;

int		zoom(int keycode, int x, int y, t_fractol *s_fractol);
int		key_hook(int keycode, t_fractol *fractol);
int		check_arguments(int argc, char **argv);
int		close_program(t_fractol *fractol);
int		color(int i, t_fractol *fractol);
double	atf( char *str);
void	my_img_pixel_put(t_fractol *fractol, int x, int y, int color);
void	mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	burning(t_fractol *fractol);
void	choose(t_fractol *fractol);
void	change_color(int keycode, t_fractol *fractol);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:49:23 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/03/08 20:49:24 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


int	color_rgb(int i);

void	my_colors(int keycode, t_fractol *fractol)
{
	if (keycode == 49)
		fractol->color = 'k';
	else if (keycode == 50)
		fractol->color = 'j';
	else if (keycode == 51)
		fractol->color = 'r';
	else if (keycode == 52)
		fractol->color = 'g';
	else if (keycode == 53)
		fractol->color = 'b';
	//my_fractal(mlx);
}

int	get_color(int i, t_fractol *fractol)
{
    
	if (fractol->color == 'k')
		return (i * 0x00ABCDEF);
		//return (color_rgb(i));
	else if (fractol->color == 'j')
		return (i * 0x00FEDCBA);
	else if (fractol->color == 'r')
		return ((i * 65536) + 1966080);
	else if (fractol->color == 'g')
		return ((i * 256) + 10000);
	else if (fractol->color == 'b')
		return ((i * 256) + 100);
	return (0);
}

int	color_rgb(int i)
{
	int	r;
	int	g;
	int	b;

	
	
	r = (int)(9 * (1 - i) * pow(i, 3) * 255);
	g = (int)(15 * pow((1 - i), 2) * pow(i, 2) * 255);
	b = (int)(8.5 * pow((1 - i), 3) * i *255);
	return (i << 24 | r << 16 | g << 8 | b);
		
		

}
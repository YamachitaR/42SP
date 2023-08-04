/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:39:25 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/03 00:14:51 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(int i, t_fractol *fractol)
{
	if (fractol->color == 1)
		return (i * 0x00ABCDEF);
	if (fractol->color == 2)
		return (i * 0x00FEDCBA);
	if (fractol->color == 3)
		return (i * 0x00ABCABC);
	return (0);
}

void	change_color(int keycode, t_fractol *fractol)
{
	if (keycode == 97)
		fractol->color = 1;
	else if (keycode == 115)
		fractol->color = 2;
	else if (keycode == 100)
		fractol->color = 3;
	choose(fractol);
}

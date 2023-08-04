/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/03 00:36:49 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	message(void);
static int	check_number(char *nbr);

int	check_arguments(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp ("mandelbrot", argv[1], ft_strlen ("mandelbrot")) == 0)
			return (1);
		if (ft_strncmp ("burning", argv[1], ft_strlen ("burning")) == 0)
			return (1);
		message ();
		return (0);
	}
	if (argc == 4)
	{
		if (ft_strncmp("julia", argv[1], ft_strlen ("julia")) == 0)
		{
			if (check_number (argv[2]) != 0 && check_number (argv[3]) != 0)
				return (1);
		}	
		message ();
		return (0);
	}
	message ();
	return (0);
}

static void	message(void)
{
	ft_putstr_fd("the arguments is wrong!!!", 1);
	ft_putstr_fd("\nExample:", 1);
	ft_putstr_fd("\n./fractol mandelbrot", 1);
	ft_putstr_fd("\n./fractol burning ", 1);
	ft_putstr_fd("\n./fractol julia x.xxx  x.xxx\n", 1);
	ft_putstr_fd("\nwhere x represents digit", 1);
	ft_putstr_fd("\nExample: ./fractol julia -0.4  0.6\n", 1);
}

static int	check_number(char *nbr)
{
	int	index;
	int	point;

	point = 0;
	index = 0;
	if (nbr[index] == '+' || nbr[index] == '-')
		index ++;
	if (nbr[index] == '.' || !nbr[index])
		return (0);
	while (nbr[index])
	{
		if (ft_isdigit(nbr[index]) == 0)
		{
			if (nbr[index] != '.' || point > 0 || !nbr[index +1])
				return (0);
			point ++;
		}
		index ++;
	}
	return (1);
}

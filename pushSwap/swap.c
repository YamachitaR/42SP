/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:53:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 19:04:48 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *nbr, int size)
{
	int	temp;

	if (size >= 2)
	{
		temp = nbr[0];
		nbr[0] = nbr[1];
		nbr[1] = temp;
	}
}

void	sa(t_data *data)
{
	swap(data->a, data->size_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_data *data)
{
	swap(data->b, data->size_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_data *data)
{
	swap(data->a, data->size_a);
	swap(data->b, data->size_b);
	ft_putendl_fd("ss", 1);
}

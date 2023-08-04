/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:22:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 19:07:10 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(int *nbr, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = nbr[0];
		ft_memmove(&nbr[0], &nbr[1], (size -1) * sizeof(int));
		nbr[size - 1] = temp;
	}
}

void	ra(t_data *data)
{
	rotate(data->a, data->size_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_data *data)
{
	rotate(data->b, data->size_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_data *data)
{
	rotate(data->a, data->size_a);
	rotate(data->b, data->size_b);
	ft_putendl_fd("rr", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:51:25 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 19:11:02 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(int *nbr, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = nbr[size - 1];
		ft_memmove(&nbr[1], &nbr[0], (size -1) * sizeof(int));
		nbr[0] = temp;
	}
}

void	rra(t_data *data)
{
	reverse_rotate(data->a, data->size_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_data *data)
{
	reverse_rotate(data->b, data->size_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_data *data)
{
	reverse_rotate(data->a, data->size_a);
	reverse_rotate(data->b, data->size_b);
	ft_putendl_fd("rrr", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:13:54 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 19:12:23 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data)
{
	if (data->size_a > 0)
	{
		ft_memmove(&data->b[1], &data->b[0], (data->size_b - 0) * sizeof(int));
		data->b[0] = data->a[0];
		data->size_b ++;
		ft_memcpy(&data->a[0], &data->a[1], (data->size_a -1) * sizeof(int));
		data->size_a --;
		ft_putendl_fd("pb", 1);
	}
}

void	pa(t_data *data)
{
	if (data->size_b > 0)
	{
		ft_memmove(&data->a[1], &data->a[0], (data->size_a -0) * sizeof(int));
		data->a[0] = data->b[0];
		data->size_a ++;
		ft_memcpy(&data->b[0], &data->b[1], (data->size_b -1) * sizeof(int));
		data->size_b --;
		ft_putendl_fd("pa", 1);
	}
}

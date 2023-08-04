/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 06:28:32 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 20:39:40 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (0);
		i ++;
	}
	return (1);
}

void	radix(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (!check_sort(data))
	{
		j = 0;
		while ((j < data->size_a + data->size_b) && !check_sort(data))
		{
			if ((data->a[0] >> i) & 1)
				ra(data);
			else
				pb(data);
			j ++;
		}
		i ++;
		while (data->size_b > 0)
			pa(data);
	}
}

int	sa_rra(t_data *data)
{
	if (data->size_a == 2)
	{
		if (data->a[0] > data->a[1])
		{
			sa(data);
			return (1);
		}
	}
	if (data->size_a > 2)
	{
		if (data->a[0] < data->a[1] && data->a[1] > data->a[data->size_a - 1])
		{
			rra(data);
			return (1);
		}
		if ((data->a[0] > data->a[1] && data->a[1] < data->a[data->size_a -1]) \
		|| (data->a[0] > data->a[1] && data->a[1] > data->a[data->size_a -1]))
		{
			sa(data);
			return (1);
		}
	}
	return (0);
}

void	small_sort(t_data *data)
{
	while (!check_sort(data) || data->size_b != 0)
	{
		if (!sa_rra(data))
		{
			if (!check_sort(data))
				pb(data);
			else
				pa(data);
		}
	}
}

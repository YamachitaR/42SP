/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:29:37 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 18:54:06 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smallest_number(int *array, int size)
{
	int	i;
	int	value;

	i = 0;
	value = array[0];
	while (i < size)
	{
		if (array[i] < value)
			value = array[i];
		i ++;
	}
	return (value);
}

static void	positive(int *array, int *positive, int size)
{
	int	value;
	int	i;
	int	small;

	value = 0;
	small = smallest_number(array, size);
	while (value < size)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == small)
			{
				positive[i] = value;
				value ++;
				small ++;
				i = -1;
			}
			i ++;
		}
		small ++;
	}
}

void	assign_value(int argc, char **argv, t_data *data)
{
	int	i;
	int	*temp;

	temp = malloc(sizeof(int) * (argc -1));
	data->a = malloc(sizeof(int) * (argc -1));
	data->size_a = argc -1;
	data->b = malloc(sizeof(int) *(argc -1));
	data->size_b = 0;
	i = 0;
	while (i < argc - 1)
	{
		temp[i] = ft_atoi(argv[i + 1]);
		i ++;
	}
	positive(temp, data->a, argc - 1);
	free (temp);
}

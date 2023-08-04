/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:27:54 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/06/22 19:43:27 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(t_data *data)
{
	free(data->a);
	free(data->b);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_argument(argc, argv))
		return (0);
	assign_value (argc, argv, &data);
	if (argc > 15)
		radix(&data);
	else
		small_sort(&data);
	ft_free(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_pthread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:56:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 09:08:07 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int	ft_philo_pthread(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_create(&data->pthread[i], NULL, &ft_philo, & philo[i]))
			return (ft_error_pthread());
	}
	ft_monitoring (philo, data->number_of_philosophers, data->time_to_die);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_join (data->pthread[i], NULL);
	return (0);
}

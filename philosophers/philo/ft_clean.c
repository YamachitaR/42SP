/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:56:59 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 07:42:44 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int	ft_clean(t_data *data, t_philo *philo)
{
	int	i;

	pthread_mutex_destroy (philo->fork_first);
	pthread_mutex_destroy (philo->fork_second);
	pthread_mutex_destroy (philo->mutex_print);
	pthread_mutex_destroy (&philo->mutex_philo);
	pthread_mutex_destroy (&philo->mutex_time);
	free (philo);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i]);
	free (data->forks);
	free (data->pthread);
	free (data);
	return (0);
}

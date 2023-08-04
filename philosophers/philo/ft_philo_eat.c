/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:37:04 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 09:32:48 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_full(t_philo *philo);

int	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock (philo->fork_first);
	if (ft_print(philo, FORK))
	{
		pthread_mutex_unlock (philo->fork_first);
		return (1);
	}
	pthread_mutex_lock(philo->fork_second);
	if (ft_print(philo, FORK))
	{
		pthread_mutex_unlock (philo->fork_first);
		pthread_mutex_unlock (philo->fork_second);
		return (1);
	}
	if (ft_print(philo, EAT))
	{
		pthread_mutex_unlock (philo->fork_first);
		pthread_mutex_unlock (philo->fork_second);
		return (1);
	}
	ft_mutex_set_time(&philo->time_meal, &philo->mutex_time,
		ft_time_epoch_in_ms());
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->fork_first);
	pthread_mutex_unlock(philo->fork_second);
	return (ft_philo_full(philo));
}

static int	ft_philo_full(t_philo *philo)
{
	if (ft_mutex_get(&philo->status, &philo->mutex_philo) != DINNER)
		return (1);
	if (philo->max_eat == -1)
		return (0);
	if (!(--philo->max_eat))
	{
		ft_mutex_set(&philo->status, &philo->mutex_philo, FULL);
		return (1);
	}
	return (0);
}

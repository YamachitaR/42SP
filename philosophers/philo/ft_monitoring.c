/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:33:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 11:34:01 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_update_status(t_philo *philo, int size);
static int	ft_monitoring_time(t_philo *philo, int i, int size,
				long int time_life);

int	ft_monitoring(t_philo *philo, int size, long int time_life)
{
	int	i;
	int	count_philo_enough;

	i = 0;
	count_philo_enough = 0;
	while (1)
	{
		if (ft_monitoring_time(philo, i, size, time_life))
			return (0);
		if (ft_mutex_get(&philo[i].status, &philo[i].mutex_philo) == FULL)
			count_philo_enough ++;
		if (count_philo_enough == size)
			return (0);
		i ++;
		if (i == size)
		{
			count_philo_enough = 0;
			i = 0;
		}
		usleep (100);
	}
	return (0);
}

static void	ft_update_status(t_philo *philo, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_mutex_set (&philo[i].status, &philo[i].mutex_philo, OFF);
		i ++;
	}
}

static int	ft_monitoring_time(t_philo *philo, int i,
				int size, long int time_life)
{
	if (ft_time_epoch_in_ms() - ft_mutex_get_time(&philo[i].time_meal,
			&philo[i].mutex_time) > time_life)
	{
		ft_update_status(philo, size);
		ft_print(philo, DIED);
		return (1);
	}
	return (0);
}

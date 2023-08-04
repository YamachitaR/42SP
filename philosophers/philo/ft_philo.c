/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:05:25 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 09:43:19 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

static void	*ft_philo_one(t_philo *philo);

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->number_philo == 1)
		return (ft_philo_one(philo));
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		if (ft_philo_eat(philo))
			return (NULL);
		if (ft_philo_sleep(philo))
			return (NULL);
		if (ft_philo_think(philo))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

static void	*ft_philo_one(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_first);
	ft_print(philo, FORK);
	pthread_mutex_unlock(philo->fork_first);
	return (NULL);
}

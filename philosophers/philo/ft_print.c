/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:03:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 11:30:59 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int	ft_print(t_philo *philo, int flag)
{
	long	timestam;

	timestam = ft_time_epoch_in_ms() - ft_mutex_get_time(&philo->time_start,
			&philo->mutex_time);
	pthread_mutex_lock(philo->mutex_print);
	if (flag == DIED)
		printf("%5ld %3d died\n", timestam, philo->id);
	if (ft_mutex_get(&philo->status, &philo->mutex_philo)
		!= DINNER || flag == DIED)
	{
		pthread_mutex_unlock(philo->mutex_print);
		return (1);
	}
	if (flag == FORK)
		printf("%5ld %3d has taken a fork\n", timestam, philo->id);
	else if (flag == EAT)
		printf("%5ld %3d is eating\n", timestam, philo->id);
	else if (flag == SLEEP)
		printf("%5ld %3d is sleeping\n", timestam, philo->id);
	else if (flag == THINK)
		printf("%5ld %3d is thinking\n", timestam, philo->id);
	pthread_mutex_unlock(philo->mutex_print);
	return (0);
}

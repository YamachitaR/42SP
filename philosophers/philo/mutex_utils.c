/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:33:36 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 09:42:05 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_get(int *get, pthread_mutex_t *mutex)
{
	int	tmp;

	pthread_mutex_lock(mutex);
	tmp = *get;
	pthread_mutex_unlock(mutex);
	return (tmp);
}

void	ft_mutex_set( int *nbr, pthread_mutex_t *mutex, int value)
{
	pthread_mutex_lock(mutex);
	*nbr = value;
	pthread_mutex_unlock(mutex);
}

long int	ft_mutex_get_time(long int *time, pthread_mutex_t *mutex)
{
	long int	tmp;

	pthread_mutex_lock(mutex);
	tmp = *time;
	pthread_mutex_unlock(mutex);
	return (tmp);
}

void	ft_mutex_set_time(long int *nbr, pthread_mutex_t *mutex, long int value)
{
	pthread_mutex_lock(mutex);
	*nbr = value;
	pthread_mutex_unlock(mutex);
}

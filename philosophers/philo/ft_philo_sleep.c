/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:24:55 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 09:09:33 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_sleep(t_philo *philo)
{
	if (ft_print(philo, SLEEP))
		return (1);
	usleep(philo->time_sleep * 1000);
	return (0);
}

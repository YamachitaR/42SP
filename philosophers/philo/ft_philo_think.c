/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:22:02 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 09:43:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int	ft_philo_think(t_philo *philo)
{
	if (ft_print(philo, THINK))
		return (1);
	usleep(philo->time_eat * 0.7);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:15:29 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 07:30:14 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int	ft_error_malloc(void)
{
	printf ("\nMalloc showed error\n");
	return (1);
}

int	ft_error_mutex(void)
{
	printf("\nMutex init showed error\n");
	return (1);
}

int	ft_error_pthread(void)
{
	printf ("Pthread create returned error!\n");
	return (1);
}

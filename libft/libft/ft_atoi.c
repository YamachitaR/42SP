/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:35:20 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/03/10 08:05:09 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		positive;
	size_t	i;

	if (!str)
		return (0);
	positive = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-' )
	{
		i ++;
		positive = -1;
	}
	else if (str[i] == '+')
		i ++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i ++;
	}
	return (result * positive);
}

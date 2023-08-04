/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:16:37 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/09/30 03:56:12 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = malloc (len1 + len2 + 1);
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, len1 + 1);
	ft_strlcpy(strjoin + len1, s2, len2 + 1);
	return (strjoin);
}

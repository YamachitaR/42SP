/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:21:15 by ryoshio-          #+#    #+#             */
/*   Updated: 2021/11/28 18:04:58 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<stdlib.h>
# include<unistd.h>

char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_putchar_int(char c);
int		ft_putstr_int(char *s);
int		ft_putnbr_int(int nbr);
int		ft_putunbr_int(unsigned int n);
int		puthexa(unsigned long int nbr, char *hexa);
int		ft_putpointer(void *p);

#endif
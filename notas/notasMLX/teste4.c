/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:25:34 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/03/08 20:43:43 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include<math.h>

#include <stdio.h>

double atf(char *str)
{
    double atf;
    int base;
	int i;
    
    base = 1;
    i =1;
    while( i< (int)ft_strlen(ft_strchr(str, '.')))
    {
        base *=10;
        i ++;
    }
    
    atf=(float)ft_atoi(str);
    if(str[0]!='-')
        atf+=(float)ft_atoi(ft_strchr(str, '.')+1)/base;
    else 
         atf-=(float)ft_atoi(ft_strchr(str, '.')+1)/base;
    return (atf);  
}

int main(void)
{
   
    
     printf("%f\n", atf("-0.476"));

     
    return (0);
}

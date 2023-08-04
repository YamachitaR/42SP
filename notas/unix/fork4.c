/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 03:03:00 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/12 03:23:40 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    int id = fork();
    
    if (id != 0)
	{
		printf("Entrei no if\n");
		fork();
		printf("depois do fork do if\n");
	}
    printf("Adivinha o que vai acontecer? \n");
    return(0);
}
/*
primeiro fork vai ter duas bivorcação 
1º vai entrar no if ( vai causa "Entei no if")
2º Vai seguir reto  (vai causa "depois do fork")

Segundo fork vai causa os restante 

*/
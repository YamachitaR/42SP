/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:19:41 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/12 03:09:27 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    int id = fork();
    printf("id: %d\n", id);
    return (0);
}

/*
Fork seria tipo uma bifurcação, por isso que o printf é exercutado duas vezes. 
Repare que o valor do id muda 
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:54:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/12 02:58:49 by ryoshio-         ###   ########.fr       */
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
    if (id == 0)
        printf("Child process \n");
    else
        printf("main process \n");
    return(0);
}

/*
Primeiro é o exercutado o principal e depois o filho

*/
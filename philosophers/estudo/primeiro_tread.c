/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primeiro_tread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:17:27 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/07 15:30:50 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Retirado do livro Sistema Operacional

*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
    /* Esta funcao imprime o identificador do thread e sai. */
    printf("Ola mundo. Boas vindas do thread %d\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[ ])
{
 /* O programa principal cria 10 threads e sai. */
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    for(i=0; i < NUMBER_OF_THREADS; i++) 
    {
        printf("Metodo Main. Criando thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
        if (status != 0) 
        {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
    }
    exit(NULL);
}
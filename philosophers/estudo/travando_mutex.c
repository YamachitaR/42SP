/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travando_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:20:31 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/11 20:00:34 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Objetivo mostrar como "mutex" trava para que outras treds não entra, 
alem disso faz com que outras tred fique na espera para entrar

*/

# include<pthread.h>//thread
# include<unistd.h>//write
# include<stdlib.h>//malloc
# include<stdio.h>//printf
# include<sys/time.h>



#define NUMBER_OF_THREADS 10


pthread_mutex_t trava;

void *trava_tread(void *tid)
{
    int i = (int) tid;
    
 
    pthread_mutex_lock(&trava);
    printf("Esta travado: %d \n", i);
    sleep(1);
    pthread_mutex_unlock(&trava);
  
    
    return(NULL);
}

int main(int argc, char *argv[ ])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    pthread_mutex_init(&trava, NULL);
    for(i=0; i < NUMBER_OF_THREADS; i++) 
    {
       // printf("Metodo Main. Criando thread %d\n", i);
        status = pthread_create(&threads[i], NULL, trava_tread, (void *)i);
       
        if (status != 0) 
        {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
    }
    for(i=0; i < NUMBER_OF_THREADS; i++) 
    {
        status=pthread_join(&threads[i], NULL);
        if (status != 3) 
        {
            printf("Oops. join deu pau %d\n", status);
            exit(-1);
        }
  
    }

  
    pthread_mutex_destroy(&trava);

    
    return(0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:30:44 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/10 03:42:15 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

#define QTHREAD 100

pthread_mutex_t print;

void printar(int thread, int valor_k, int flag)
{
    if(flag == 1)
        printf("\nMetodo Main. Criando thread %d \n", thread);
    else
        printf("\n A tread %d valor de k= %d", thread, valor_k);
}

void *funcao_thread(void *i)
{
	int j =(int) i;
	int k = 0;
	
	while(k< 10)
	{
	//estou travado para garantir que entre uma tread de cada vez
		pthread_mutex_lock(&print); 
		printar(j, k, 0);
	    pthread_mutex_unlock(&print); //destravando
		k++;
	}
	return(NULL);
}

int main(void)
{

	int i = 0;

	//criando nossa tread
	pthread_t threads[QTHREAD];

	//print é uma variavel global (da uma olhada la em cima)
	// serve para bloquea e permiti acesso da tread
	pthread_mutex_init(&print, NULL); // inicializando a variavel

	while(i<QTHREAD)
	{
        pthread_mutex_lock(&print);
        printar(i, 0, 1);
        pthread_mutex_unlock(&print);

		pthread_create(&threads[i], NULL,funcao_thread , (void *)i);
		i++;
	}

	i =0;
	while(i <QTHREAD )
		pthread_join(threads[i++], NULL);

	// analogia. estamos dando free na nossa variavel 
	pthread_mutex_destroy(&print);
	return (0);

}
























/*
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h> 
# include <pthread.h>

#define QTHREAD 10

pthread_mutex_t print;

void *funcao_thread(void *i)
{
   
    int k;
    
  int j = (int) i;
   

 
     k = 0;
    while(k< 100)
    {
        pthread_mutex_lock(&print); 
        printf("\n A tread %d  valor de k= %d", j, k);
        pthread_mutex_unlock(&print);
        k++;
    }

    return(NULL);
}

int main(void)
{
    int i=0;
    pthread_t threads[QTHREAD];
   
    pthread_mutex_init(&print, NULL);
   // pthread_mutex_init(&mutex, NULL);
    while(i<QTHREAD)
    {
        // se tirar comentario vai da merda, pois vai entrar em confrito
        // Acredito ocorre confrito pois uma hora vai ter mais de dois mandado simutaneamente
        printf("\nMetodo Main. Criando thread \n %d", i);
        pthread_create(&threads[i], NULL,funcao_thread , (void *)i);
        i++;
    }
    i =0;
    while(i <QTHREAD )
        pthread_join(threads[i++], NULL);
   pthread_mutex_destroy(&print);
    return (0);
}

*/
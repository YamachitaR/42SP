#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "unistd.h"


#define N 5                    // numeros de filosofos
#define V_ESQUERDA (i + N - 1)%N // vizinhos a esquerda
#define V_DIREITA (i + 1) % N  // vizinhos a direita
#define PENSANDO 0             // filosofo pensando
#define FAMINTO 1              // filosofo tentando pegar o garfo
#define COMENDO 2              // filosofo comendo
enum
{
    false,
    true
};

void comendo(int);
void pense(int i, int garfo);
int test(int i);
int pegue_garfos(int i);
int retorne_garfos(int i, int garfo);
void *filosofo(void *);


pthread_t filosofos[N];    //vetor threads dos filosofos
int estado[N];             //vetor de estado de todos os filosofos
pthread_mutex_t travas[N]; //um semaforo por filosofo
pthread_mutex_t trava;     //exclusão para regiões criticas

int main()
{
    long i;
    for (i = 0; i < N; i++)
        estado[i]=PENSANDO;
    pthread_mutex_init(&trava, NULL); //inicializando mutex das regiões criticas (exclusão mutua)
    for (i = 0; i < N; i++)
        pthread_mutex_init(&travas[i], NULL); //inicializando thread de cada filosofo
    for (i = 0; i < N; i++)
        pthread_create(&filosofos[i], NULL, filosofo, (void *)i); // criando as threads (filosofos)
    for (i = 0; i < N; i++)
        pthread_join(filosofos[i], NULL); //unindo as threads com a main
    pthread_mutex_destroy(&trava);        // desfazendo mutex das regiãos criticas (exclusão mutua)
    for (i = 0; i < N; i++)
        pthread_mutex_destroy(&travas[i]); //desfazendo mutex de cada filosofo
    pthread_exit(NULL);
}
void coma(int i, int garfo)
{
    if(garfo == 2)
    {
        printf("Filosofo %d comendo!\n", i);
        usleep(300000);

    }

}
void pense(int i, int garfo)
{
    if(garfo == 0)
    {
    pthread_mutex_lock(&trava);     //entrando na região crítica
    estado[i] = PENSANDO;  
    printf("\nFilosofo %d pensando!", i);   
    printf(" %d %d %d %d %d\n", estado[0],estado[1], estado[2],estado[3], estado[4]);
    pthread_mutex_unlock(&trava);
  
    usleep(1000);

    }

}
int  test(int i) //verifica o filosofo i e seus vizinhos
{
    if (estado[i] == FAMINTO && estado[V_ESQUERDA] == PENSANDO && estado[V_DIREITA] == PENSANDO)
    {
        estado[i] = COMENDO;
        printf("\nFilosofo %d comendo!", i);
        printf(" %d %d %d %d %d\n", estado[0],estado[1], estado[2],estado[3], estado[4]);
        usleep(5);
       pthread_mutex_lock(&travas[V_ESQUERDA]);
        pthread_mutex_lock(&travas[V_DIREITA]);
        return(2);
    }else if(estado[i] == FAMINTO && estado[V_ESQUERDA] == PENSANDO )
        pthread_mutex_lock(&travas[V_ESQUERDA]);
    return(1);
}
int pegue_garfos(int i)
{
    int garfo =0;
    pthread_mutex_lock(&trava);     //entrando na região crítica
    estado[i] = FAMINTO;   
     printf(" %d %d %d %d %d\n", estado[0],estado[1], estado[2],estado[3], estado[4]);         //setando filosofo i
    garfo=test(i);                        //tentar pegar os dois garfos
      //saindo da região crítica
   
    pthread_mutex_unlock(&trava);
    return(garfo);               //bloqueando se os garfos não foram pegados
}
int retorne_garfos(int i, int garfo)
{
    pthread_mutex_lock(&trava); //entrando na região crítica
    estado[i] = PENSANDO;  
    if(garfo ==2)
    {
       
        pthread_mutex_unlock(&travas[V_ESQUERDA]);
        pthread_mutex_unlock(&travas[V_DIREITA]);;
           pthread_mutex_unlock(&trava);   //saindo da região crítica
    return(0);
    }
    else
        pthread_mutex_unlock(&travas[V_ESQUERDA]);
    pthread_mutex_unlock(&trava);   //saindo da região crítica
    return(1);
    
}
void *filosofo(void *i)
{
    long id;
    id = (long)i;
    int garfo;
    while (true)
    {
 
        pense(id, garfo);          //filosofo começa a pensar
        garfo=pegue_garfos(id);   //pega dois garfos da mesa
        coma(id, garfo);           //comendo
        garfo=retorne_garfos(id, garfo); // coloca os dois garfos de volta na mesa
    }
    pthread_exit(NULL);
}
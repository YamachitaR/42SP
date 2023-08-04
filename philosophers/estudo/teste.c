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
void pensando(int);
void test(int);
void pegue_garfos(int);
void retorne_garfos(int);
void *filosofo(void *);


pthread_t filosofos[N];    //vetor threads dos filosofos
int estado[N];             //vetor de estado de todos os filosofos
pthread_mutex_t travas[N]; //um semaforo por filosofo
pthread_mutex_t trava;  


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
void coma(int i)
{
    printf("Filosofo %d comendo!\n", i);
}
void pense(int i)
{
    printf("Filosofo %d pensando!\n", i);
}
void test(int i) //verifica o filosofo i e seus vizinhos
{
    if (estado[i] == FAMINTO && estado[V_ESQUERDA] != COMENDO && estado[V_DIREITA] != COMENDO)
    {
        estado[i] = COMENDO;
        pthread_mutex_unlock(&travas[i]);
    }
}
void pegue_garfos(int i)
{
    pthread_mutex_lock(&trava);     //entrando na região crítica
    estado[i] = FAMINTO;            //setando filosofo i
    test(i);                        //tentar pegar os dois garfos
    pthread_mutex_unlock(&trava);   //saindo da região crítica
    pthread_mutex_lock(&travas[i]); //bloqueando se os garfos não foram pegados
}
void retorne_garfos(int i)
{
    pthread_mutex_unlock(&trava); //entrando na região crítica
    estado[i] = PENSANDO;         //filosofo terminou de comer
    test(V_ESQUERDA);             //ver se o vizinho da esquerda pode comer
    test(V_DIREITA);              // ver se o vizinho da direita pode comer
    pthread_mutex_lock(&trava);   //saindo da região crítica
}
void *filosofo(void *i)
{
    long id;
    id = (long)i;
    while (true)
    {
        pense(id);          //filosofo começa a pensar
        pegue_garfos(id);   //pega dois garfos da mesa
        coma(id);           //comendo
        retorne_garfos(id); // coloca os dois garfos de volta na mesa
    }
    pthread_exit(NULL);
}

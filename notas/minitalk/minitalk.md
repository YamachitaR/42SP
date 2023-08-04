# O que é PID?

O que PID, é o ID do processo, ou seja, o numero do processo que  faz com o processo 

Vamos supor que rodamos o seguinte código. 


```c
#include <stdio.h>
# include <signal.h>
int main (void)
{
	int i;
	i = 0;
	
	while( i< 100)
	{
		printf("%d\n", i);
		// sleep esta com parametro 1, isso significa que ele pausa cada 1 segundo.
		sleep(1);
		i++;
	}
	
	return (0);
}

```
Rodamos ele, no outro terminal nos usamos o comando "ps -au" (esse comando para saber PID do programa), depois usamos "kill <PID>" (seria mater o programa com PID ).

se demos um "kill -l" podemos ver todas as opções (cujo nome é sinais). Por padrão o sinal mandado é SIGTERM. Para "kill <opção> <PID>". A opção pode ser pelo numero ou pelo nome, pelo fato de mudar o numero de acordo com  o sistema operacional, então é melhor usar o nome. 

``` C
#include <stdio.h>
# include <signal.h>

void nome(int signal)
{
	printf("nome\n");
}


int main (void)
{
	int i;
	i = 0;

	// signal: é uma função, que a recener um sinal vai exercutar a função recebido
	// 1º parametro é opção do kill
	// 2º é função do tipo "void função (int numero)"
	signal(15, nome);

	while( i< 8)
	{
		printf("%d\n", i);
		sleep(1);
		i++;
	}
	return (0);
}
```

Repare, "signal" esta fora do while, ao usar o comando "kill 15 <PID>" em outro terminal, 






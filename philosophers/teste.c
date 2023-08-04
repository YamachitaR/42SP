#include <stdio.h> // printf
#include <unistd.h> // sleep
#include <pthread.h>
#include <stdlib.h> // malloc

void	*thread_routine(void *arg)
{
	int	*int_p1;
	int	*int_p2;

	int_p1 = (int *)arg;
	int_p2 = (int *)malloc(sizeof(int));
	*int_p2 = 1;
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("Thread here! %i %d %d\n", i, *int_p1, *int_p2);
		(*int_p1)++;
		(*int_p2)++;
	}
	return (int_p2);
}

int	main(int argc, char *argv[])
{
	pthread_t	thread_1;
	int			arg;
	int			*ret;

	arg = 5;
	printf("Thread with args\n");
	pthread_create(&thread_1, NULL, &thread_routine, &arg);
	for (int i = 0; i < 3; i++)
	{
		sleep(2);
		printf("Main here! %i\n", i);
	}
	pthread_join(thread_1, (void *)&ret);
	printf("Thread's done: arg = %d\n", arg);
	printf("Thread's return: ret = %d\n", *ret);
	return (0);
}
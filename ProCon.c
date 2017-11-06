#include<pthread.h>
#include<stdio.h>
#include <semaphore.h>

#define BUFFER_SIZE 1024

int n;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full, mutex;

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	if (argc != 2)
	{
		fprintf(stderr, "usage: ./a.out <positive integer>\n");
		exit(0);
	}
	/* get default attribute */
	pthread_attr_init(&attr);
	/*create the thread */
	pthread_create(&tid, &attr, runner, argv[1]);
	printf("Main thread is busy doing something ...\n");
	while (sum <= 1)
	{
		printf("%d ", sum);
	}
	/* wait for the thread to exit */
	pthread_join(tid, NULL);
	printf("sum = %d \n", sum);
}

void *runner(void *param)
{

	int i, upper = atoi(param);
	sum = 0;

	for(i = 1; i <= upper; i++)
	{
		sum += i;
		// printf("%d ", sum);
	}
	pthread_exit(0);
}

void initialize(){
	/* Create the semaphore empty and initialize it to BUFFER_SIZE */
	sem_init(&empty, 0, BUFFER_SIZE);
	
	sem_init(&full, 0, 0);

	/* create the semaphore */
	sem_init(&mutex, 0, 1);
}

void consumer(){
	do{
	/* acquire the semaphore */
	sem_wait(&mutex);	
	
	/*** critical section ***/
	


	/* release the semaphore */
	sem_post(&mutex);

	}while(1)
}

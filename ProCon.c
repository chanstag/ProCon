#include<pthread.h>
#include<stdio.h>
#include <semaphore.h>

#define BUFFER_SIZE 1024

int n = 12;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full, mutex;

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
	int i;

	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	if (argc != 2)
	{
		fprintf(stderr, "usage: ./a.out <positive integer>\n");
		exit(0);
	}
	for(i = 0; i < argv[1]; i++){
		
		/* get default attribute */
		pthread_attr_init(&attr);
		/*create the thread */
		pthread_create(&tid, &attr, producer, NULL);

	}
		
	for(i = 0; i < argv[1]; i++){
		/* get default attribute */
		pthread_attr_init(&attr);
		/*create the thread */
		pthread_create(&tid, &attr, consumer, NULL)
	}
	/* wait for the thread to exit */
	pthread_join(tid, NULL);
	for(int k = 0; k < out; k++){
		printf("value = %d \n", k);
	}
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
	sem_wait(&full)
	sem_wait(&mutex);	
	
	/*** critical section ***/
	
	buffer[out] = 0; 

	/* release the semaphore */
	sem_post(&mutex);
	sem_post(&empty);

	out = (out + 1) % BUFFER_SIZE;
	if(out == n){
		pthread_exit(); 
	}
	}while(1)
}

void producer(){

do{

	in = (in + 1) % BUFFER_SIZE;
	if(in == n){
		pthread_exit();		
	}
        /* acquire the semaphore */
        sem_wait(&empty);
	sem_wait(&mutex);
	
        /*** critical section ***/

	 buffer[in] = in; 

        /* release the semaphore */
        sem_post(&mutex);
	sem_post(&full);

        }while(1)


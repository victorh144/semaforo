
#include <pthread.h> //libreria necesaria para trabajar con hilos
#include <semaphore.h>
#include <stdio.h>
#include <windows.h>

#define NR_LOOP 10000 //definicion de la constante
static void * thread_1_function(void* arg); //definicion de los hilos
static void * thread_2_function(void* arg); //definicion de los hilos
static int counter = 0; //definicion de la variable conuter

sem_t sem1; //Declaracion del semaforo

int main (void)

{
	pthread_t thread_1, thread_2;
	
	sem_init(&sem1, 0, 1); //Inicializacion de la funcion del semaforo en un hilo
	
	pthread_create(&thread_1, NULL, *thread_1_function, NULL); //creacion de las funciones de hilos 1
	pthread_create(&thread_2, NULL, *thread_2_function, NULL); //creaciojn de la funcion hilo 2
	
	pthread_join(thread_1, NULL); //funcion que permite termina el hilo
	pthread_join(thread_2, NULL);
	
	printf("valor counter %d \n", counter);
	return 0;
	}

static void * thread_1_function(void* arg)
{
	for (int i = 0; i<NR_LOOP; i++) //incrementa en 10.000 el valor
	{
		sem_wait(&sem1); // Funcion que decrementa el valor 
		counter += 1;
		sem_post(&sem1); //incrementa una unidad del semaforo
	}
}
static void * thread_2_function(void* arg) //decrementa en 10.000 el valor
{
	for (int i = 0; i<NR_LOOP; i++)
	{
		sem_wait(&sem1); // Funcion que incrementa el valor
		counter -= 1;
		sem_post(&sem1); //incrementa una unidad del semaforo
	}
}





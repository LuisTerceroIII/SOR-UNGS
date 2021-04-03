/*

    Conjunto de threads que se ejecutan siguiendo la siguiente secuencia : 

    2 procesos se ejecuta, se esperan 2 segundos.
    2 procesos, 2 segundos, 2 procesos, 2 segundos...

*/


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

static void *printThreadID();

sem_t permitidos;
sem_t aux;

static int procesos = 0;


int main() {
    sem_init(&permitidos,0,2);
    sem_init(&aux,0,1);

    pthread_t thread1;
    pthread_create(&thread1,NULL,*printThreadID,NULL);

    pthread_t thread2;
    pthread_create(&thread2,NULL,*printThreadID,NULL);

    pthread_t thread3;
    pthread_create(&thread3,NULL,*printThreadID,NULL);

    pthread_t thread4;
    pthread_create(&thread4,NULL,*printThreadID,NULL);

     pthread_t thread5;
    pthread_create(&thread5,NULL,*printThreadID,NULL);

    pthread_t thread6;
    pthread_create(&thread6,NULL,*printThreadID,NULL);

    pthread_t thread7;
    pthread_create(&thread7,NULL,*printThreadID,NULL);

    pthread_t thread8;
    pthread_create(&thread8,NULL,*printThreadID,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_join(thread4,NULL);
    pthread_join(thread5,NULL);
    pthread_join(thread6,NULL);
    pthread_join(thread7,NULL);
    pthread_join(thread8,NULL);

    sem_destroy(&aux);
    sem_destroy(&permitidos);
    pthread_exit(NULL);
    return 0;
}

static void *printThreadID() {
    pthread_t threadId;
    threadId = pthread_self();

    sem_wait(&aux);
    sem_wait(&permitidos);
    printf("Thread Id : %d \n",threadId);
    procesos++;
    if(procesos >= 2) {
            sleep(2);
            sem_post(&permitidos);
            sem_post(&permitidos);
            procesos = 0;
            
    }
    sem_post(&aux);
   
}
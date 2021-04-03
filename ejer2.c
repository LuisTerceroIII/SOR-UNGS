/*

    Conjunto de threads que se ejecutan siguiendo la siguiente secuencia : 

    Primer proceso espera 8 segundos antes de ejecutarse, ESTO SE HACE POR UNICA VEZ.
    Luego se ejecutan sin sincronizacion ("normalmente").

*/


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>


static void *printThreadID();

sem_t seguir;

static short ejecutados = 0;


int main() {

    sem_init(&seguir,0,1);

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

    sem_destroy(&seguir);
    pthread_exit(NULL);
    return 0;
}

static void *printThreadID() {
    pthread_t threadId;
    threadId = pthread_self();

    sem_wait(&seguir);
    if(ejecutados == 0) {
        sleep(8);
        ejecutados++;
    }
    printf("Thread Id : %d \n",threadId);
    sem_post(&seguir);
   
}
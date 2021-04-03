/*
    "El barbero dormilon"
        El barbero atiende 1 persona por vez.
        El barbero tiene n sillas de espera.
        El barbero se duerme sin clientes.
        El cliente despierta al barbero.
        Si no hay sillas el cliente se va.
        Si hay sillas espera.
*/


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>


static void *cortePelo();
static void *extraccion(void *extract);

sem_t sem_barbero;
sem_t sem_sillas;
sem_t sem_clientes;

int main() {

    sem_init(&sem_barbero,0,1);
    sem_init(&sem_sillas,0,10);
    sem_init(&sem_clientes,0,0);

    pthread_t thread1;
    pthread_create(&thread1,NULL,*cortePelo,NULL);

    pthread_t thread2;
    pthread_create(&thread2,NULL,*cortePelo,NULL);

    pthread_t thread3;
    pthread_create(&thread3,NULL,*cortePelo,NULL);

    pthread_t thread4;
    pthread_create(&thread4,NULL,*cortePelo,NULL);

     pthread_t thread5;
    pthread_create(&thread5,NULL,*cortePelo,NULL);

    pthread_t thread6;
    pthread_create(&thread6,NULL,*cortePelo,NULL);

    pthread_t thread7;
    pthread_create(&thread7,NULL,*cortePelo,NULL);

    pthread_t thread8;
    pthread_create(&thread8,NULL,*cortePelo,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_join(thread4,NULL);
    pthread_join(thread5,NULL);
    pthread_join(thread6,NULL);
    pthread_join(thread7,NULL);
    pthread_join(thread8,NULL);



    sem_destroy(&sem_barbero);
    sem_destroy(&sem_sillas);
    sem_destroy(&sem_clientes);
    pthread_exit(NULL);
    return 0;
}

static void *cortePelo() {
    sem_wait(&sem_sillas);
    sem_post(&sem_clientes);
    sem_wait(&sem_barbero);
    printf("Cortando...\n");
    sleep(2);
    printf("Me cortaron el pelo =) \n");
  
    sem_wait(&sem_clientes);
    sem_post(&sem_sillas);
    sem_post(&sem_barbero);
}


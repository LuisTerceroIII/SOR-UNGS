/*

    Conjunto de threads simulan cuenta bancaria, controlar transacciones.
    Cuenta
        Deposito
        Extraccion

    La cuenta puede quedar con saldo negativo
*/


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>


static void *deposito(void *depo);
static void *extraccion(void *extract);

sem_t sem_saldo;

static int saldo = 0;

int main() {

    sem_init(&sem_saldo,0,1);

    pthread_t thread1;
    pthread_create(&thread1,NULL,*deposito,(void *) 200);

    pthread_t thread2;
    pthread_create(&thread2,NULL,*deposito,(void *) 200);

    pthread_t thread3;
    pthread_create(&thread3,NULL,*deposito,(void *) 200);

    pthread_t thread4;
    pthread_create(&thread4,NULL,*deposito,(void *) 200000);

     pthread_t thread5;
    pthread_create(&thread5,NULL,*extraccion,(void *) 200);

    pthread_t thread6;
    pthread_create(&thread6,NULL,*extraccion,(void *) 200);

    pthread_t thread7;
    pthread_create(&thread7,NULL,*extraccion,(void *) 200);

    pthread_t thread8;
    pthread_create(&thread8,NULL,*extraccion,(void *) 200);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_join(thread4,NULL);
    pthread_join(thread5,NULL);
    pthread_join(thread6,NULL);
    pthread_join(thread7,NULL);
    pthread_join(thread8,NULL);

    printf("Saldo total : %d \n",saldo);

    sem_destroy(&sem_saldo);
    pthread_exit(NULL);
    return 0;
}

static void *deposito(void *depo) {
    int deposito = (intptr_t) depo;
    sem_wait(&sem_saldo);
    saldo = saldo + deposito;
    sem_post(&sem_saldo);
}

static void *extraccion(void *extract) {
    int extraccion = (intptr_t) extract;
    sem_wait(&sem_saldo);
    saldo = saldo - extraccion;
    sem_post(&sem_saldo);
}
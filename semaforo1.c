#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

#define NRO_LOOP 10000

static int counter = 0;
static void * plusOne();
static void * substractOne();

// Semaforo MUTEX
sem_t counter_sem;

int main() {

    pthread_t threadOne, threadTwo;

    sem_init(&counter_sem,0,1);

    pthread_create(&threadOne,NULL,*plusOne,NULL);
    pthread_create(&threadTwo,NULL,*substractOne,NULL);

    pthread_join(threadOne,NULL);
    pthread_join(threadTwo,NULL);

    printf("Counter : %d\n",counter);

    return 0;
}

static void * plusOne() {
    
    for (int i = 0; i < NRO_LOOP; i++)
    {
        sem_wait(&counter_sem);
        counter++;
        sem_post(&counter_sem);
    }
    
    pthread_exit(NULL);
}

static void * substractOne() {

    for (int i = 0; i < NRO_LOOP; i++)
    {
        sem_wait(&counter_sem);
        counter--;
        sem_post(&counter_sem);
    }
    
    pthread_exit(NULL);
    
}
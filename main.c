#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define P sem_wait
#define V sem_post

// Exo 1

int global = 10;

void *fct_thread() {
    for (int i = 0; i < 10; ++i) {
        sleep(1);
        global++;
        printf("%d\n", global);
    }
}

// Exo 2

sem_t sem1;
sem_t sem2;

void *jemes(){
    printf("Je");
    V(&sem1);
    P(&sem2);
    printf("mes ");
    V(&sem1);
}

void *syncthreads(){
    P(&sem1);
    printf(" synchronise ");
    V(&sem2);
    P(&sem1);
    printf("Threads");
}

// Exo 3

sem_t barriere;

void* t1(){
    sleep(2);
    printf("T1 : Travail termine !\n");
    V(&barriere);
    sleep(10);
    printf("T1 : fin du thread\n");
}

void* t2(){
    sleep(5);
    printf("T2 : Travail termine !\n");
    V(&barriere);
    sleep(10);
    printf("T2 : fin du thread\n");
}

void* t3(){
    sleep(4);
    printf("T3 : Travail termine !\n");
    V(&barriere);
    sleep(10);
    printf("T3 : fin du thread\n");
}

int main() {
      // Exo 1
//    pthread_t thread_id_1;
//    pthread_t thread_id_2;
//    pthread_t thread_id_3;
//
//    pthread_create(&thread_id_1, NULL, fct_thread, NULL);
//    pthread_create(&thread_id_2, NULL, fct_thread, NULL);
//    pthread_create(&thread_id_3, NULL, fct_thread, NULL);
//
//
//    pthread_join(thread_id_1, NULL);
//    pthread_join(thread_id_2, NULL);
//    pthread_join(thread_id_3, NULL);

        // Exo 2
//    pthread_t thread_id_1;
//    pthread_t thread_id_2;
//
//    pthread_create(&thread_id_1, NULL, jemes, NULL);
//    pthread_create(&thread_id_2, NULL, syncthreads, NULL);
//    pthread_join(thread_id_1, NULL);
//    pthread_join(thread_id_2, NULL);

    // Exo 3
    sem_init(&barriere, 0 , -3);
    pthread_t thread_id_1;
    pthread_t thread_id_2;
    pthread_t thread_id_3;

    pthread_create(&thread_id_1, NULL, t1, NULL);
    pthread_create(&thread_id_2, NULL, t2, NULL);
    pthread_create(&thread_id_3, NULL, t3, NULL);

    sleep(3);
    printf("Barriere : Travail termine, en attente...\n");
    for(int i = 0;i<3;++i){
        P(&barriere);
    }


    printf("Barriere : Peut continuer !\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t mutexA;
pthread_mutex_t mutexB;
int cont=0;

void *routineA(void *t){
    long my_id=(long)t;
    while(true)
    {
        printf("[%ld] Acceso\n",my_id);
        pthread_mutex_lock(&mutexA);
        pthread_mutex_lock(&mutexB);
        printf("[%ld] Procesamiento sobre recurso compartido: %d\n",my_id,cont++);
        pthread_mutex_unlock(&mutexB);
        pthread_mutex_unlock(&mutexA);
    }
    pthread_exit(EXIT_SUCCESS);
}

void *routineB(void *t){
    long my_id=(long)t;
    while(true)
    {
        printf("[%ld] Acceso\n",my_id);
        pthread_mutex_lock(&mutexB);
        pthread_mutex_lock(&mutexA);
        printf("[%ld] Procesamiento sobre recurso compartido: %d\n",my_id,cont++);
        pthread_mutex_unlock(&mutexA);
        pthread_mutex_unlock(&mutexB);
       
    }
    pthread_exit(EXIT_SUCCESS);
}

int main()
{
    long t1=1, t2=2;
    pthread_t th1,th2;
    
    pthread_mutex_init (&mutexA,NULL);
    pthread_mutex_init (&mutexB,NULL);
    pthread_create(&th1,NULL,routineA,(void *) t1);
    pthread_create(&th2,NULL,routineB,(void *) t2);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_mutex_destroy(&mutexA);
    pthread_mutex_destroy(&mutexB);
    
    return EXIT_SUCCESS;
        
}

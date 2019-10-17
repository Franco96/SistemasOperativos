 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define WHITE "\033[m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0 ;
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void *inc_count(void *t){
    
 int i;
 
 long my_id = (long)t;
 
    for(i=0;i<TCOUNT;i++){
        
        pthread_mutex_lock(&count_mutex);
        count++;
        if(count == COUNT_LIMIT){
            pthread_cond_signal(&count_threshold_cv);
            printf(RED"inc_count(): hilo %ld , count = %d Umbral alcanzado.\n"WHITE,my_id,count);
        }
        
        printf(GREEN"inc_count(): hilo %ld , count = %d unlocking mutex.\n"WHITE,my_id,count);
        pthread_mutex_unlock(&count_mutex);
        sleep(1);
        
    }
 
    pthread_exit(NULL);
    
}

void *watch_count(void *t){
    
    long my_id = (long)t;
    
    printf("watch_count(): hilo %ld\n",my_id);
    
    pthread_mutex_lock(&count_mutex);
    
    while(count<COUNT_LIMIT){
        pthread_cond_wait(&count_threshold_cv,&count_mutex);
        printf("watch_count(): hilo %ld señal de condicion recibida.\n",my_id);
        count+=100;
         printf("watch_count(): hilo %ld count = %d.\n",my_id,count);
    }
    
    pthread_mutex_unlock(&count_mutex);
    pthread_exit(NULL);
    
    
}


int main(int argc,char *argv[]){
    
    int i ; long t1 = 1 , t2=2, t3=3;
    
    pthread_t threads[3];
    
    pthread_attr_t attr;
    
    pthread_mutex_init(&count_mutex,NULL);
    
    pthread_cond_init(&count_threshold_cv,NULL);
    
    pthread_attr_init(&attr);
    
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    
    pthread_create(&threads[0],&attr,watch_count,(void *)t1);
    pthread_create(&threads[1],&attr,inc_count,(void *)t2);
    pthread_create(&threads[2],&attr,inc_count,(void *)t3);
    
    for(i=0;i<3;i++){
        pthread_join(threads[i],NULL);
    }
    
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mutex);
    
    pthread_cond_destroy(&count_threshold_cv);
    
    
    return EXIT_SUCCESS;
}





























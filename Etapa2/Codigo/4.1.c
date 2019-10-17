#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TOTAL 100000000

pthread_mutex_t lock;

int sum = 0;

void *sumamucho(void *param){
    
    int i;
    
     //pthread_mutex_lock(&lock);
    for(i = 0; i <TOTAL ; i++){
    
        sum += 1;
        
    }
    
   // pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main(){
    
    pthread_t tid1,tid2;
    
    pthread_create(&tid1,NULL,sumamucho,NULL);
    
    pthread_join(tid1,NULL);
    
    pthread_create(&tid2,NULL,sumamucho,NULL);
    
    
    
    pthread_join(tid2,NULL);
    
    printf("Total es %d\n",sum);
    
    return EXIT_SUCCESS;
}




/*A) condicion de carrera : se produce cuando varios procesos acceden y manipulan
 *  los mismo datos concurrentemente y el resultado de la ejecucion depende del orden particular de acceso.
 *    
 * 
 */

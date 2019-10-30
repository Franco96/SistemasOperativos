#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>


sem_t sem_lau;




int main(){
    
    sem_init(&sem_lau,0,0);
      
    sem_post(&sem_lau);
    
      sem_wait(&sem_lau);
  
    
    
    
    printf("ejemplo de dos operaciones wait sobre el semaforo\n");
    
  
    
    printf("ejemplo de una operacion signal sobre el semaforo\n");
    
    sem_post(&sem_lau);
    
    
    //cerrar semaforo
    
    sem_destroy(&sem_lau);
    
    
    exit(EXIT_SUCCESS); 
    
    
}

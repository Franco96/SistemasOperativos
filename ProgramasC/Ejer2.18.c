#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define TAM 100


void *sacar_no_p(void *arg){
    
    int *nros_p = (int *) arg;
    int i, j, h;
    
    for(i = 2; i <TAM ; ++i){
        
        if(nros_p[i]){
            
            for(h = 2 ; i*h <= TAM ; ++h)
                nros_p[i*h] = 0;
        }
        
    }
    
}




void main(void){
    
    int i = 0;
    
    pthread_t hilo_p;
    
    int *numeros = (int*) malloc ((TAM)*sizeof(int));
    
    numeros[0] = 0;
    numeros[1] = 0;
    
    for(i = 2; i <TAM;i++){numeros[i] = 1;}
    
    pthread_create(&hilo_p,NULL,sacar_no_p,(void*)numeros);
    
    pthread_join(hilo_p,NULL);
    
    
 for(i = 0 ; i<TAM;i++){
     
     if(numeros[i]){
         
         printf("%d - ",i);
    }
     
}   

printf("\n");

free(numeros);
    
}

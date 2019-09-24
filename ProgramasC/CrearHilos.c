#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>




void *id(){
    
  
     
  
    
    
    printf("soy el hilo con id %i \n",(int)pthread_self());
    
    
}




void main(int argc, char *argv[]){
    
   
    int n;
    
    n =  atoi(argv[1]);
    
    
    
    pthread_t hilo_p [n];
   
    
    int i;
    
 for(i = 0 ; i<n;i++){
      
   
    pthread_create(&hilo_p[i],NULL,id,NULL);
    
 }
     
    for(i = 0 ; i<n;i++){
      
   
     pthread_join(hilo_p[i],NULL);
    
 }  
     
     
    


    
}
 

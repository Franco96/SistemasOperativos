#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


int cont = 5;





void *hilo11(){
    
    cont++;
    printf("soy el hilo 1 con cont = %i \n",cont);
    
    
}

void *hilo22(){
    
    cont--;
   printf("soy el hilo 2 con cont = %i \n",cont);
    
    
}





void main(int argc, char *argv[]){
    
   
   
    
    
    pthread_t hilo1;
    pthread_t hilo2;
    
   
    
    
    
      
   
 
    pthread_create(&hilo2,NULL,hilo22,NULL); 
       pthread_create(&hilo1,NULL,hilo11,NULL);

      pthread_join(hilo1,NULL);
        pthread_join(hilo2,NULL);
  
        printf("valor de cont es : %i\n",cont);
    


    
} 

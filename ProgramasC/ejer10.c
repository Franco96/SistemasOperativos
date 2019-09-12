#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main(void){

    int i = getpid();
    
    printf("Soy el proceso padre mayor de todos el mas grande\n");
    printf("%i\n",i);
    
    
     int pid = fork();
    
     
     if(pid>0){
      
         printf("Soy el proceso padre mayor de todos el mas grande mi pid es %i\n",getpid());
         
        }else{//Entra en el hijo
        
                    printf("Soy el proceso hijo mi pid es  %i y el de papa es %i\n",getpid(),getppid());
            
                    printf("ahora quiero tener un hijo asi mi papa es abuelo\n");
                    
                    int pid2 = fork();
                    
                            if(pid2>0){
                                
                            printf("soy el hijo mi pid es %i y ya tuve un hijo \n",getpid());
                        }
                           else{
                               printf("soy el nieto mi pid es %i y el de mi papa es %i\n",getpid(),getppid());
                           }
        }
        
    
     

    
    
    
    return 0;
    
}

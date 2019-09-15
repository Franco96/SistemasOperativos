
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    
    
   
    int n = 3;
    
    int i = 0;
    
    int pid1 = 1;
       
     
      
        for(i= 0; i<n;i++){
       
                
            
                            if(pid1>0){//Entra el padre
            
                                     pid1 = fork();
                                     
                                    if  (pid1 == 0 )
                                            { //Entra el hijo 
                                            printf("Soy el hijo %i (%d, hijo de %d)\n",i,getpid(), getppid());
                                            
                                                
                                            }

                            }
            
            

            }
    
            
        
    }
        

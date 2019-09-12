
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    
    
   
    int n = 3;
    
  
    
    int i;
    
   /* 
    printf("el padre del padre %i\n",getppid());
    
    
    
    
    pid = fork();
    
    printf("El PID ES:%i\n",pid);
    
    if(pid==0){
     printf("Soy el hijo con PID %i y mi papa es %i\n",getpid(),getppid());
    }
    if(pid>0){ /*entra el padree*/
        
     
        
        int pid1 = 1;
        
        for(i= 0; i<n;i++){
       
                
            
                            if(pid1>0){
            
                                     pid1 = fork();
                                    if  (pid1 == 0 )
                                            { /* hijo */
                                            printf("Soy el hijo %i (%d, hijo de %d)\n",i,getpid(), getppid());
                                          
                                                
                                            }

                            }
            
            

            }
    
            
        
    }
        

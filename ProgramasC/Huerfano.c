
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    
    
   
    pid_t child_pid;
    
     
    child_pid = fork();
   
    
    
    
    if(child_pid == 0 ){//entra al hijo 
    
        //sleep(5);
        
        printf("Holaaaaa\n");
        printf("Soy el hijo con PID %d y mi papa es %d\n",getpid(),getppid());
        
    }
    else{
        
        if(child_pid >0 ){//Entra el padre
            
            wait(NULL);
            
        }
        
    }
    
    
    
    
    
    
    
    
            
        
    }
        
 


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    
    
   
    pid_t child_pid;
    
     

    int i;
    
    for(i= 0;i<10;i++){
   
    child_pid = fork();

    
    if(child_pid == 0 ){//entra al hijo 
    
       
        sleep(1);
        printf("Soy el hijo %d con PID %d y mi papa es %d\n",(i+1),getpid(),getppid());
       
        
    }
    else{//Entra el padre
        
           exit(0);
            
        }
        
    }
    
    
      
    return 0;
        
    }
    
    
    
    
  
    
    
            
        
    
        
 

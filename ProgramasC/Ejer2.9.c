#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int value = 5;


int main(){

    pid_t pid;
    
    pid = fork();
    
    if(pid == 0){ /*proceso hijo*/
    
        value +=15;
        sleep(5);
        printf("Soy el hijo imprimo el value : %i\n",value);
        return 0;
    }
      else {         
                     
                      if (pid>0) {
        
                          wait(&pid);
                             
                            
                                printf("Padre : valor = %d\n",value);/*linea A*/
                            return EXIT_SUCCESS;   
                     }
        
    }
    
}


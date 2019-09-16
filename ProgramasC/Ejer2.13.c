
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>




void crearHijos(int contador,int cantHijos){

 
    
    
        if(cantHijos > 0){
            
            
            pid_t child_pid;
            
            
            child_pid = fork(); //Creo el hijo 
            

                    
            
                    if(child_pid >0 ){ //Entra el padre
                        
                      
                        
                        wait(NULL);                    
                        crearHijos(contador+1,cantHijos - 1);
                     
                           
                         
                    }
                   else{ //Entra el hijo 
                        
                
                        printf("Soy el hijo %d (%d, hijo de %d)\n",contador,getpid(), getppid());
                                sleep(contador);
                                exit(1);
                        
                    }
            
            
              
            
        }         
    
    
}

    






int main(int argc, char *argv[]){
    
   
    int n;
    
    n =  atoi(argv[1]);
    
   
   crearHijos(1,n);
                    
            
            

            
    
            
        
    }
        

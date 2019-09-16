
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    
   
    int n;
    
   // printf("Cantidad de parametos %d\n",argc);
    
    n =  atoi(argv[1]);
    
  //  printf("Primer Parametro es %d\n",n);
    
    
 
    
    int i;
    
     pid_t pid;
      
        for(i= 1; i<=n;i++){
       
                
                        pid = fork();
                                     
                      if  (pid == 0 ){ //Entra el hijo 
                                        printf("Soy el hijo %i (%d, hijo de %d)\n",i,getpid(), getppid());
                                        sleep(i);
                                        break;   //con esto el hijo sale del for
                                }
                       else{//Entra el padre
                           
                      wait(NULL);     
                           
                      }         
                                

                        
                    
            
            

            }
    
            
        
    }
        

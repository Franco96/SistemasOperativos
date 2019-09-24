    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>
   #include <stdio.h>
    
    int main ()
    {
      pid_t child_pid;
     
      int i;
      int n = 60;
      
      for(i = 0;i<n;i++){
         
          child_pid = fork ();
          
          
      if (child_pid > 0) {
          
          if(i == (n-1)){
       
          printf("Soy el proceso padre %d y espero 60 segundos antes de terminar, de mi hijo no se nada.\n",getpid());
          sleep(60);
          }
          
      }
      else {
        exit (0);
      }
          
    }
      
   
      
      return 0;
    }

 

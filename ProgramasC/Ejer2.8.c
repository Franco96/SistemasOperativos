 
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

static int idata = 111; /* Asignado en segmento de datos */

int main(int argc, char *argv[]){
    
    int  istack = 222; /* Asignado en segmento de pila */
    pid_t childPid;
    
    switch (childPid = fork()){
        case -1:
                perror(" ERRORr");
        case 0:
                printf("soy el proceso bomba hijo\n");
                idata *=3;
                istack *=3;
                break;
        default:
            printf("Soy el proceso lea padre\n");
            sleep(3);
            break;
    }
    
    /* Tanto el padre como el hijo entra acá */
    printf("PID=%ld %s idata=%d istack=%d\n",(long) getpid(),
         (childPid==0) ? "(hijo)" : "(padre)" ,idata ,istack);
    
    exit(EXIT_SUCCESS);
    
    
                
}

#include <stdlib.h>
#include <stdio.h> 
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>




int main(){
    
    mqd_t mq;

    struct mq_attr attr;
    
    char bufer[100]="";
    
    /* Inicializacion de los atributos de la cola */
    attr.mq_flags=0;
    attr.mq_maxmsg=10;
    attr.mq_msgsize=10;
    attr.mq_curmsgs=10;
    
    
    
    
    if (( mq = mq_open("/cola_prueba",O_RDWR, NULL,&attr))== -1){
        //creacion
        perror("mq_open");
        return EXIT_FAILURE;
    }
    
   
    mq_receive(mq,bufer,sizeof(bufer),NULL);//recibir mensaje
    
    printf("Recibi: %s\n",bufer);
    
    if (mq_close(mq)==-1)
    {
        perror("mq_close");
        return EXIT_FAILURE;
        
    }
    
    
} 

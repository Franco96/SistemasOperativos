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
   
    
    /* Inicializacion de los atributos de la cola */
    attr.mq_flags=0;
    attr.mq_maxmsg=10;
    attr.mq_msgsize=100;
    attr.mq_curmsgs=10;
    
    if (( mq = mq_open("/cola_prueba",O_CREAT | O_RDWR, 0666,&attr))== -1){
        //creacion
        perror("mq_open");
        return EXIT_FAILURE;
    }
    
    mq_send(mq,"hola bomba todo bien totito tenes la mema lista!",sizeof("hola bomba todo bien totito tenes la mema lista!"),0); //enviar mensaje
   
    
   
    
    if (mq_close(mq)==-1)
    {
        perror("mq_close");
        return EXIT_FAILURE;
        
    }

   
   
    return EXIT_SUCCESS;
    
}

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para la funcion strlen
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    
    const int SIZE = 4096;
    
    int shm_fd;
    
    void *addr;
    
    shm_fd = shm_open("/shared_memory_gdistel", O_CREAT | O_RDWR ,0640);
    
    if(shm_fd >= 0){
    
        printf("se creo con exito el segmento de memoria compartida shared_memory_gdistel.\n");
        printf("el descriptor de archivo es %i\n",shm_fd);
    }
    
    
    //especificar el tamaño del segmento de memoria compartida 
      
      ftruncate(shm_fd,SIZE);
      
      //Maperar el segmento de memoria compartida en el espacio de memoria del 
      //proceso
      
      addr = mmap(0,SIZE, PROT_READ | PROT_WRITE , MAP_SHARED,shm_fd ,0); // man r mmap
    if(addr == MAP_FAILED){
        printf("Map failed\n");
        return EXIT_FAILURE;
    }
    
    //escribir el segmento de memoria compartida 
    memcpy(addr,"jejejeje\n",strlen("jejejeje  "));
    
    return EXIT_SUCCESS;
    
}

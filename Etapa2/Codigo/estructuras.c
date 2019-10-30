#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

/* definimos una estructura para cds */
struct cd 
{
     char titulo[30];
     char artista[25];
     float precio;
     int *canciones;
};

int main(void)
{
    
    
    
    
	struct cd *Cd2 = (struct cd*) malloc(sizeof(struct cd));
	
	
	
	
	/* asignamos valores a los tipos de datos del cd2 */
	//strcpy(Cd2->titulo, "New Age"); 

	/* la forma de insertar valores a un 
	 * tipo char en una estructura es usando strcpy
	 * de la libreria string.h 
	 */
	//strcpy(Cd2->artista, "Old Man");
	Cd2->precio = 15.00;
	//(*Cd2->canciones) = 12;
	
	/* la forma de acceder a los valores de una estructura */
	/* es usando el "." despues de la definicion del dato*/
	
    
    
	//printf("\n Cd 2");
	//printf("\n Titulo: %s ", Cd2->titulo);
	//printf("\n Artista: %s ", Cd2->artista);	
	//printf("\n Total Canciones: %i ", (*Cd2->canciones));
	printf("Precio Cd: %.2f \n", Cd2->precio); /* el .2 que esta entre %f 
                                                   * sirve para mostrar unicamente 
                                                   * 2 decimales despues del punto*/
	
	
	return 0;
} 

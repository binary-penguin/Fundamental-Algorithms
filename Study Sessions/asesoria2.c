# include <stdio.h>
# include <string.h>


char nombre[10]; 



main() {
    
    
	for (int i = 0; i < sizeof(nombre); i++) {
    
        printf("Posicion [%d] = %d \n", i, nombre[i]);
        
    }
    
    strcpy(nombre, "Hola Mundo");
    
    for (int i = 0; i < sizeof(nombre); i++) {
    
        printf("Posicion [%d] = %d \n", i, nombre[i]);
        
    }
}

# include <stdio.h>
# include <string.h>


char nombre[10]; 



main() {
	int contador0simple = 0; // '\0'
    int contador0triple = 0; // '\000'
    int contador0entero = 0; // 0
    int contadorNULL = 0; // NULL
    
    //strcpy(nombre, "Hola Mundo");
    //printf("%s", nombre);
    
	for (int i = 0; i < sizeof(nombre); i++) {
    	
        if (nombre[i] == '\0') {
            printf("\nEncontre 0 simple en posicion %d (%c). \n", i, (nombre[i]));
            contador0simple++;
        }
        if (nombre[i] == 0) {
            printf(" Encontre 0 entero en posicion %d (%c). \n", i, nombre[i]);
            contador0entero++;
        }
        if (nombre[i] == '\000') {
            printf(" Encontre 0 triple en posicion %d (%d). \n", i, nombre[i]);
            contador0triple++;
        }
        if (nombre[i] == NULL) {
            printf(" Encontre NULL en posicion %d (%c). \n", i, nombre[i]);
            contadorNULL++;
        }
    }
    /*printf("\n");
    printf("------------------------------------\n");
    printf("No. 0 simple: %d\n", contador0simple);
    printf("No. 0 triple: %d\n", contador0triple);
    printf("No. 0 entero: %d\n", contador0entero);
    printf("No. NULL    : %d\n", contadorNULL);
    printf("------------------------------------\n");
    
	strcpy(nombre, "Juan");
    
       	// nombre[0] = J
    	// nombre[1] = U
    	// nombre[2] = A
    	// nombre[3] = N
    	// nombre[4] = \0
    	// nombre[5] = \0
    	// nombre[..] = \0
    	// nombre[9] = \0
    	
    	// Esperaría 6 campos (4-9) vacíos.

    contador0simple = 0;
    contador0triple = 0;
    contador0entero = 0;
    contadorNULL = 0;
    
    for (int i = 0; i < sizeof(nombre); i++) {
    	
 

        if (nombre[i] == '\0') {
            printf("\nEncontre 0 simple en posicion %d (%c). \n", i, (nombre[i]));
            contador0simple++;
        }
        if (nombre[i] == 0) {
            printf(" Encontre 0 entero en posicion %d (%c). \n", i, nombre[i]);
            contador0entero++;
        }
        if (nombre[i] == '\000') {
            printf(" Encontre 0 triple en posicion %d (%d). \n", i, nombre[i]);
            contador0triple++;
        }
        if (nombre[i] == NULL) {
            printf(" Encontre NULL en posicion %d (%c). \n", i, nombre[i]);
            contadorNULL++;
        }
    }
    printf("\n");
    printf("------------------------------------\n");
    printf("No. 0 simple: %d\n", contador0simple);
    printf("No. 0 triple: %d\n", contador0triple);
    printf("No. 0 entero: %d\n", contador0entero);
    printf("No. NULL    : %d\n", contadorNULL);
    printf("------------------------------------\n");
    
    // \0 Se comporta igual que \000 y que 0:
	// Pregunta 1: ¿Es lo mismo? 
	// Pregunta 2: ¿Con qué seguridad puedo implementar cualquiera de ellos sabiendo que no habrá problemas?
	// Pregunta 2.1 : ¿Es lo mismo \00000000?
	// Pregunta 3: ¿NULL es entonces 0?
	// Pregunta 4: ¿Por qué no puedo hacer print de nombre[i] pero sí compararlo?
	
	// Pregunta 5: ¿Porqué VS Code lo rellena de basura? ¿Será cosa del compilador? OK
	*/
}

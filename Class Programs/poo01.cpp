# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona {
	public: // Atributos de la clase Persona
		char nom[21], ap[21];
		int edad;
	public: // Métodos de la clase Persona
		Persona() {
			printf("Se ejecuta el constructor\n");
			strcpy(nom, "Juan");
			strcpy(ap, "Reyes");
			edad = 25;
		}
		void muestra() {
			printf("Nombre     : %s\n", nom);
			printf("Ap. Paterno: %s\n", ap);
			printf("Edad       : %d\n", edad);
		}
};
main() {
	Persona objeto;
	objeto.muestra();
}

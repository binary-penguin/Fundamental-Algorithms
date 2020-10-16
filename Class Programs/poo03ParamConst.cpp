# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona {
	public: // Atributos de la clase Persona
		char nom[21], ap[21];
		int edad;
	public: // Métodos de la clase Persona
		Persona(char nom_[21], char ap_[21], int edad_) {
			printf("Se ejecuta el constructor\n");
			strcpy(nom, nom_);
			strcpy(ap, ap_);
			edad = edad_;
		}
		void muestra() {
			printf("Nombre     : %s\n", nom);
			printf("Ap. Paterno: %s\n", ap);
			printf("Edad       : %d\n", edad);
		}
};
class Estudiante:public Persona {
	public:
		char mat[4], car[5];
	public:
		Estudiante() {
			strcpy(mat, "123");
			strcpy(car, "LAE");
		}
		void muestra_estudiante() {
			printf("Matr%ccula: %s\n", 161, mat);
			printf("Carrera   : %s\n", car);
			
			
			
		}
		
};
main() {
	Estudiante A1;
	A1.muestra();
	A1.muestra_estudiante();
}

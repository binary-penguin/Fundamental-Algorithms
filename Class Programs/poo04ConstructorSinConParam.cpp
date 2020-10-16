# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona {
	public: // Atributos de la clase Persona
		char nom[21], ap[21];
		int edad;
	public: // Métodos de la clase Persona
		Persona(char nom_[21], char ap_[21], int edad_) {
			printf("Se ejecuta el constructor  CON PARAMETROS\n");
			strcpy(nom, nom_);
			strcpy(ap, ap_);
			edad = edad_;
		}
		Persona() {
			printf("Se ejecuta el constructor SIN PARAMETROS\n");
			strcpy(nom, "JUAN");
			strcpy(ap, "PISTOLAS");
			edad = 35;
		}
		void muestra() {
			printf("Nombre     : %s\n", nom);
			printf("Ap. Paterno: %s\n", ap);
			printf("Edad       : %d\n", edad);
		}
};
class Computadora {
	public:
		int dd, ram;
		char proce[16], moni[16];
	public:
		Computadora(char proce_[16], char moni_[16], int dd_, int ram_) {
			strcpy(proce, proce_);
			strcpy(moni, moni_);
			dd = dd_;
			ram = ram_;
		}
		Computadora() {
			strcpy(proce, "Intel i7");
			strcpy(moni, "17''");
			dd = 100;
			ram = 12;
		}
		void muestra() {
			printf("Disco Duro     : %d Mb\n", dd);
			printf("Memoria RAM    : %d Gb RAM\n", ram);
			printf("Procesador     : %s\n", proce);
			printf("Monitor        : %s\n", moni);
		}
		
};
main() {
	Persona objeto("JUAN", "PISTOLAS", 35);
	objeto.muestra();
	Persona objeto2;
	objeto2.muestra();
	
	Computadora modelo("Intel i2", "18'", 500, 8);
	modelo.muestra();
	Computadora modelo1;
	modelo1.muestra();
	
}

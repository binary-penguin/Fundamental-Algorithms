class Persona {
	public: // Atributos de la clase Persona
		char nom[21], ap[21];
	public: // Métodos de la clase Persona
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
		void muestra() {
			printf("Disco Duro     : %d Mb\n", dd);
			printf("Memoria RAM    : %d Gb RAM\n", ram);
			printf("Procesador     : %s\n", proce);
			printf("Monitor        : %s\n", moni);
		}
		
};
main() {	
	Computadora modelo1;
	strcpy(modelo1.proce, "Core i5 1.8 GHz");
	strcpy(modelo1.moni, "14' No touch'");
	modelo1.dd = 500;
	modelo1.ram = 8;
	modelo1.muestra();
}

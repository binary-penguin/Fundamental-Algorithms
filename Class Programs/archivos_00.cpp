# include <stdio.h>
# include <conio.h>
# include <String.h>
# include <fstream>
using namespace std;


/*

PLACAS ALFA 7 (LLAVE) -> LLAVE MEANS IT CANNOT BE DUPLICATED
MARCA  ALFA 20 (NISSAN)
TIPO   ALFA 20 (MARCH)
MODELO INT 4 (2020)



*/


int modelo;
char falso[2], placa[8], marca[21], tipo[21];
float precio;

bool buscaPlacas(char placasAux[8]) {
	ifstream arch;
	arch.open("autos.txt", ios::in);
	while (!arch.eof()) {
		arch >> placa >> marca >> tipo >> modelo >> precio;
		if (strcmp(placa, placasAux) == 0); {
			arch.close();
			return (true);
		}
	}
	arch.close();
	return (false);
	
	   
	   
}


void agregarAutos() {
	printf("\n********************************");
	
	char placas_aux[8];
	int x = 0;
	bool existe;
	do  {
		printf("Indica las placas : "); gets(placas_aux);
		strupr(placas_aux);
		x = strlen(placas_aux);
		
		if ((x<3) || (x>7)) printf("Error, las placas tienen que tener entre 3 y 7 d�gitos.\n");
		
		bool existe = buscaPlacas(placas_aux);
		
		if (existe) {
			printf("Error, las placas se repiten.\n");
			getche();
		}
	} while (((x<3) || (x>7)) || (existe));
	
	do {
		printf("Indica la marca   : "); gets(marca);
		x = strlen(marca);
		if ((x<1) || (x>20)) printf("Error, la marca tiene que tener entre 1 y 20 d�gitos.\n"); getche();
		
	} while ((x<1) || (x>20));
	
	
	for(int i = 0; i< x; i++) if (marca[i] == ' ') marca[i] = '_';
	


    do {
		printf("Indica la marca   : \n"); gets(tipo);
		x = strlen(tipo);
		if ((x<1) || (x>20)) printf("Error, el tipo tiene que tener entre 1 y 20 d�gitos.\n"); getche();
		
	} while ((x<1) || (x>20));
	
	for(int i = 0; i< x; i++) if (tipo[i] == ' ') tipo[i] = '_';
	
	do {
		printf("Indica el modelo   : \n"); scanf("%d", &modelo);
		if (modelo < 1900) printf("Error, el modelo tiene que ser mayor a 1900.\n"); getche();
		
	} while (modelo < 1900);
	
	do {
		printf("Indica el precio   : \n"); scanf("%f", &precio);
		if (precio < 1) printf("Error, precio tiene que ser mayor a 1.\n"); getche();
		
	} while (precio < 1);
	
	
	
	printf("Indica el precio   : \n"); scanf("%f", &precio);
}

void listado_general(int op) {
	char marca_aux[21];
	int modelo_aux;
	printf(" Placas		               Marca					Tipo   Modelo	       Precio\n");
	printf("---------------------------------------------------------------------------------");
	//      1234567		12345678901234567890	12345678901234567890	1234		123456789
	
	ifstream arch;
	arch.open("autos.txt", ios::in);
	if (op == 4) printf("Indica la marca a listar: "); gets(marca_aux);
	if (op == 5) printf("Indica el modelo a listar: "); scanf("%d", &modelo_aux);
	while (!arch.eof()) {
		arch >> placa >> marca >> modelo >> precio;
		
		if (!arch.eof()) 
		{
			for(int i = 0; i< strlen(tipo); i++) if (tipo[i] == '_') tipo[i] = ' ';
			for(int i = 0; i< strlen(marca); i++) if (marca[i] == '_') marca[i] = ' ';
			if (op == 3) printf("%7s %20s %20s %4d %9.2f\n", placa, marca, tipo, modelo, precio);
			if (op == 4) && (strcmp(marca_aux, marca) == 0) printf("%7s %20s %20s %4d %9.2f\n", placa, marca, tipo, modelo, precio);	
			if (op == 5) && (modelo_aux == modelo) printf("%7s %20s %20s %4d %9.2f\n", placa, marca, tipo, modelo, precio);
			
			
		}
		
	}	
	arch.close();
	getche();
}


void consulta() {
	char placas_aux[8];
	printf("*********************************************\n");
	printf("Indica las placas a consultar	: \n"); gets(placas_aux);
	strupr(placas_aux);
	
	if (buscaPlacas(placas_aux)) {
		printf("Marca	: %s\n", marca);
		printf("Tipo	: %s\n", tipo);
		printf("Modelo	: %d\n", modelo);
		printf("Precio	: %.2f\n", precio);
		getche();
	}
}

void menu() {
	
	
	int op = 0;
	
	
	
	do {
		printf("**********************");
		printf("\n1) Agrega Autos");
		printf("\n2) Consulta Autos por placas");
		printf("\n3) Listado General");
		printf("\n4) Listado por marca");
		printf("\n5) Listado por modelo");
		printf("\n6) Terminar\n");
		printf("Indica la opci%cn : ", 162); scanf("%d", &op); gets(falso);
		
		switch(op) {
			case 1:
				agregarAutos();
				break;
			case 2:
				consulta();
				break;
			case 3:
				listado_general(op);
				break;
			case 4:
				listado_general(op);
				break;
			case 5:
				listado_general(op);
				break;	
		}
		
	} while (op != 6);
	
}

int main() {
	menu();
	
	
}

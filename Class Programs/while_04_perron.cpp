# include <stdio.h>
# include <conio.h>

int v1, v2, v3, v4, v5;
void promedio(){
	float prom;
	prom = (v1+v2+v3+v4+v5) / 5.0;
	printf("El promedio es: %.2f\n", prom);
}

void mayor() {
	int m;
	m = v1;
	
	if (v2 > m) m = v2;
	if (v3 > m) m = v3;
	if (v4 > m) m = v4;
	if (v5 > m) m = v5;
	
	printf("El mayor es: %d\n", m);
	getche();
}

void menor() {
	int m;
	m = v1;
	
	if (v2 < m) m = v2;
	if (v3 < m) m = v3;
	if (v4 < m) m = v4;
	if (v5 < m) m = v5;
	
	printf("El menor es: %d\n", m);
	getche();
}
void pideValores(){
	do{
		printf("Indica el primer valor: "); scanf("%d", &v1);
		if ((v1 < 1) || (v1 > 100)) {
			printf("Error, valor fuera de rango entre 1 y 100 . . .\n");
			
		}
	} while ((v1 < 1) || (v1 > 100));
	do{
		printf("Indica el segundo valor: "); scanf("%d", &v2);
		if ((v2 < 1) || (v2 > 100)) {
			printf("Error, valor fuera de rango entre 1 y 100 . . .\n");
			
		} 
	} while ((v2 < 1) || (v2 > 100));	
	do{
		printf("Indica el tercer valor: "); scanf("%d", &v3);
		if ((v3 < 1) || (v3 > 100)) {
			printf("Error, valor fuera de rango entre 1 y 100 . . .\n");
			
	} 
		} while ((v3 < 1) || (v3 > 100));	

	do{
		printf("Indica el cuarto valor: "); scanf("%d", &v4);
		if ((v4 < 1) || (v4 > 100)) {
			printf("Error, valor fuera de rango entre 1 y 100 . . .\n");
			
		} 
		}while ((v4 < 1) || (41 > 100));
	do{
		printf("Indica el primer valor: "); scanf("%d", &v5);
		if ((v5 < 1) || (v5 > 100)) {
			printf("Error, valor fuera de rango entre 1 y 100 . . .\n");
			
		} 
		}while ((v5 < 1) || (v5 > 100));
	}
void menu(){
	int op;
	do{
		printf("1) Promedio\n");
		printf("2) N%cmero Mayor\n", 163);
		printf("3) N%cmero Menor\n", 163);
		printf("4) Pares\n");
		printf("5) Impares\n");
		printf("6) Salir\n");
		printf("Indica op: "); scanf("%d", &op);
		switch(op) {
			case 1: promedio(); break;
			case 2: mayor(); break;
			case 3: menor(); break;
		}

		
	} while (op != 6);
}



main(){
	pideValores();
	menu();
}

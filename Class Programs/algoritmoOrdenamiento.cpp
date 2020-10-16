# include <stdio.h>
# include <conio.h>

int ar[10];
// BUBBLE ORDERING

void pide_valores() {
	
	int input;
	for (int i = 0; i <= 9; i++) {
		printf("Indica valor de posicion [%d] :", i);
		scanf("%d", &input);
		ar[i] = input;
	}
}
void ordenaBubble() {
	int aux;
	
	for (int i = 0; i <= 9; i++) {
		for (int j=i+1; j <= 9; j++) {
			
			if (ar[i] > ar[j]) {
				// aux guarda el valor
				aux = ar[i];
				// pone ambos valores iguales
				ar[i] = ar[j];
				// cambia a j por el valor guardado
				ar[j] = aux;
			
			}
		}
	}
}

void muestra_arreglo() {
	for (int i = 0; i <= 9; i++) {
		printf("Posicion [%d] : %d\n", i, ar[i]);
	}
}


main() {
	pide_valores();
	ordenaBubble();
	muestra_arreglo();
}

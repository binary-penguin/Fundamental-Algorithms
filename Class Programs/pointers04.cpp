# include <stdio.h>
# include <conio.h>

int *arr, tamanio;

void crea_arreglo() {
	printf("Indica tamano : "); scanf("%d", &tamanio);
	arr = new int[tamanio];
}
void captura_arreglo() {
	int captura;
	for (int i=0; i <tamanio; i++) {
		printf("Indica el valor de posicion %d: ", i);
		scanf("%d", &captura);
		arr[i] = captura;
		
	}
}
void muestra_arreglo() {
	for (int i=0; i< tamanio; i++) {
		printf("%d\n", arr[i]);
	}
}
void borra_arreglo() {
	delete arr;
}

main() {
	crea_arreglo();
	captura_arreglo();
	muestra_arreglo();
	borra_arreglo();
}
